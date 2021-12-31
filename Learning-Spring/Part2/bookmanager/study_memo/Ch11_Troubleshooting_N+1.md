# JPA에서의 N+1 이슈

## Fetch Type = "EAGER"와 "LAZY"의 차이

@OneToMany(fetch = FetchType.EAGER)에서 EAGER와 LAZY의 차이를 확실하게 알아보자.  
테스트 코드는 아래와 같다.

```java
@Test
@Transactional
void reviewTest() {
    List<Review> reviews = reviewRepository.findAll();

    System.out.println("전체를 가져왔습니다");
    System.out.println(reviews.get(0).getComments());
    System.out.println("첫번째 리뷰의 코멘트들을 가져왔습니다");
    System.out.println(reviews.get(1).getComments());
    System.out.println("두번째 리뷰의 코멘트들을 가져왔습니다");
}
```

---

## ● Fetch Type = EAGER

쿼리 결과 :

```text
Hibernate: 
    select
        ...
    from
        review review0_
    ...
전체를 가져왔습니다
[]
첫번째 리뷰의 코멘트들을 가져왔습니다
[]
두번째 리뷰의 코멘트들을 가져왔습니다
```

findAll을 하는 시점에 각각의 코멘트를 각각 조회를 하게되어 쿼리가 먼저 실행되며, 그 이후에 getComments를 하게되더라도 추가적으로 쿼리를 실행하는것이 아니라 영속성 컨텍스트에서 가지고있는 캐쉬를 통하여 데이터가 출력된다.

## ● Fetch Type = LAZY

```text
Hibernate: 
    select
        review0_.id as id1_6_,
        review0_.created_at as created_2_6_,
        review0_.updated_at as updated_3_6_,
        review0_.book_id as book_id7_6_,
        review0_.content as content4_6_,
        review0_.score as score5_6_,
        review0_.title as title6_6_,
        review0_.user_id as user_id8_6_ 
    from
        review review0_
전체를 가져왔습니다
Hibernate: 
    select
        comments0_.review_id as review_i5_4_0_,
        comments0_.id as id1_4_0_,
        comments0_.id as id1_4_1_,
        comments0_.created_at as created_2_4_1_,
        comments0_.updated_at as updated_3_4_1_,
        comments0_.comment as comment4_4_1_,
        comments0_.review_id as review_i5_4_1_ 
    from
        comment comments0_ 
    where
        comments0_.review_id=?
[]
첫번째 리뷰의 코멘트들을 가져왔습니다
Hibernate: 
    select
        comments0_.review_id as review_i5_4_0_,
        comments0_.id as id1_4_0_,
        comments0_.id as id1_4_1_,
        comments0_.created_at as created_2_4_1_,
        comments0_.updated_at as updated_3_4_1_,
        comments0_.comment as comment4_4_1_,
        comments0_.review_id as review_i5_4_1_ 
    from
        comment comments0_ 
    where

```

findAll을 할때 review 쿼리가 실행된다. 그리고나서 get(0) 메소드가 나올때 쿼리를 실행하고, get(1) 메소드가 나오면 다시 쿼리가 실행된다.  
이렇게 review 쿼리가 실행되고, 그 이후에 getComment 할때마다 각각의 id에 맞는 쿼리가 실행된다.  
필요한 시점에 쿼리가 실행되게 되니 일반적으로는 EAGER 타입 대비 성능에 대한 이점을 얻을 수 있다.
