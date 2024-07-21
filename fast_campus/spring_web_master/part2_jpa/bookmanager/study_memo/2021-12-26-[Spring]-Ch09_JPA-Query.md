# JPA @Query 활용하기

BookRepository class에 극단적인 메소드를 만들어보자

```java
List<Book> findByCategoryIsNullAndNameEqualsAndCreatedAtGreaterThanEqualAndUpdatedAtGreaterThanEqual(String name, LocalDateTime createdAt, LocalDateTime updatedAt);
```

이런 경우라면 가독성도 좋지 않을뿐더러 실수하기 딱 좋다.

그러므로 좀더 가독성있는 코드를 위하여 @Query 를 활용할 수 있다.  
BookRepository class에 아래와 같은 메서드를 추가해보자

```java
@Query(value = "select b from Book b " // 공백에 유의하자
    + "where name = ?1 and createdAt >= ?2 and updatedAt >= ?3 and category is null")
List<Book> findByNameRecently(String name, LocalDateTime createdAt, LocalDateTime updatedAt);
```

위의 극단적으로 긴 메소드와 같은 역할을 하지만 JPQL 이라는 문법을 통하여, Query annotation을 이용하면 좀더 가독성있는 코드를 짤수 있다.  

---

## @Param

위의 JPQL문의 ?1 ?2 ?3과 메소드의 name, createdAt, updatedAt을 순서를 맞춰주는것이 일반적인데, 이렇게하면 좀 더 신경쓸게 많아진다. 그러므로 @Param 을 이용하여 매칭을 시켜주도록 하자.

```java
@Query(value = "select b from Book b "
    + "where name = :name and createdAt >= :createdAt and updatedAt >= :updatedAt and category is null")
List<Book> findByNameRecently(
    @Param("name") String name, 
    @Param("createdAt") LocalDateTime createdAt, 
    @Param("updatedAt") LocalDateTime updatedAt
);
```

이렇게 하면 파라미터의 순서에 영향을 받지 않아지기 때문에, 로직의 변경이 자유로워지며 사이드 이펙트에서 좀더 자유로울 수 있게 된다.

---
---

## @Column(columnDefinition)

위의 코드를 찾는 data.sql문을 보면

```sql
insert into book(`id`, `name`, `publisher_id`, `deleted`) values (1, 'JPA 초격차 패키지', 1, false);
```

보다시피 createdAt 과 updatedAt이 빠져 있다. 이걸 sql문으로 일일히 넣는것보단 columnDefinition 을 활용한다.

```java
public class BaseEntity implements Auditable {

    @CreatedDate
    @Column(columnDefinition = "datetime(6) default now(6) comment '생성시간'", nullable = false, updatable = false)
    private LocalDateTime createdAt;

    @LastModifiedDate
    @Column(columnDefinition = "datetime(6) default now(6) comment '수정시간'", nullable = false)
    private LocalDateTime updatedAt;
}
```

- columnDefinition을 이용하여 해당 column의 default 값을 지정해 줄 수 있다.
- columnDefinition 은 auto-ddl을 할때 추가적인 속성값.
- 각각의 속성을 이어붙이는 방식으로 ddl 구문이 생성됨.
- comment 속성을 통하여 주석을 달아줄 수 있다.
- datetime(6) now(6) 에서 6이라는 숫자는 자리수를 의미하며, 함수라고 생각하여 datetime()으로 처리하면 오류가 발생한다.
- now() 는 시분초 까지만 나오며 now(6)는 최대 자릿수로 초보다 더 아래인 6자리 microsec가 나온다.
- 중요한 데이터는 now(6) 으로 최대한 세밀하게 데이터를 저장하여 정확하게 저장해야한다.

---
---

## @Query 좀 더 활용하기

book과 category만 따로 추출해서 찾아보는 구체 클래스를 생성한다.

```java
@Data
@AllArgsConstructor
@NoArgsConstructor
public class BookNameAndCategory {
    private String name;
    private String category;
}
```

BookRepository는 아래와 같이 @Query value를 지정해준다. class 이름을 지정할때는 directory까지 지정해줘야한다.

```java
public interface BookRepository extends JpaRepository<Book, Long>{
    ...
    @Query(value = "select new com.fastcampus.jpa.bookmanager.repository.dto.BookNameAndCategory(b.name, b.category) from Book b")
    List<BookNameAndCategory> findBookNameAndCategory();
}
```

```java
@Test
void queryTest() {
    bookRepository.findBookNameAndCategory().forEach(b -> {System.out.println(b.getName() + " : " + b.getCategory());});
}
```

---

## Paging 기능

findAll() 값에 Pageable pageable 을 넣게되면 페이지 형식의 리턴값을 줘서 페이징을 할수있도록 함.  
마찬가지로 @Query 에서도 Pageable 기능을 사용하면 페이징 기능을 사용할 수 있다.

```java
@Query(value = "select new com.fastcampus.jpa.bookmanager.repository.dto.BookNameAndCategory(b.name, b.category) from Book b")
Page<BookNameAndCategory> findBookNameAndCategory(Pageable pageable);
```

↑ 위와 같이 repository의 메소드에 Pageable 인자를 추가해준다.

```java
bookRepository.findBookNameAndCategory(PageRequest.of(1, 1)).forEach(
    BookNameAndCategory -> System.out.println(BookNameAndCategory.getName() + " : " + BookNameAndCategory.getCategory())
);

bookRepository.findBookNameAndCategory(PageRequest.of(0, 1)).forEach(
    BookNameAndCategory -> System.out.println(BookNameAndCategory.getName() + " : " + BookNameAndCategory.getCategory())
);
```

첫번째 테스트 메소드는 PageRequest를 활용하여 2번째 페이지에서 찾고, 두번째 테스트 메소드는 첫번째 페이지에서 가져온다.
