# Entity의 Listener의 활용

- @PrePersist : insert(persist) 메소드가 실행되기 전에 실행되는 메소드
- @PreUpdate : merge method가 호출되기 전에 실행되는 메소드
- @PreRemove : before delete method
- @PostPersist : insert(persist) 메소드가 실행된 후에 실행되는 메소드
- @PostRemove : merge method가 호출된 후에 실행되는 메소드
- @PostLoad : select 조회가 일어난 직후에 실행되는 메소드

```java
public class User {

    @Column(updatable = false)
    private LocalDateTime createAt;

    private LocalDateTime updateAt;


    @PrePersist
    public void prePersist() {
        this.createdAt = LocalDateTime.now();
        this.updatedAt = LocalDateTime.now();
    }

    @PreUpdate
    public void preUpdate() {
        this.updatedAt = LocalDateTime.now();
    }

}
```

user class에 createdAt, updatedAt 을 사용하여 일일히 코딩하는것보단  
@PrePersist 를 사용하여 한번에 할 수 있다.

---

## EventListener 만들기

```java
public class MyEntityListener {
    
    @PrePersist
    public void prePersist(Object obj) {
        if (obj instanceof Auditable) {
            ((Auditable) obj).setCreatedAt(LocalDateTime.now());
            ((Auditable) obj).setUpdatedAt(LocalDateTime.now());
        }
    }

    @PreUpdate
    public void preUpdate(Object obj) {
        if (obj instanceof Auditable) {
            ((Auditable) obj).setUpdatedAt(LocalDateTime.now());
        }
    }
}
```

```java
@EntityListeners(value = MyEntityListener.class)
public class User implements Auditable {
```

class에 implements Auditable 을 달고 EntityListeners annotation과 value값을 달아줌.

---

## ★ JPA 기본 Listener

main class에 @EnableJpaAuditing annotation 추가

```java
@EnableJpaAuditing
public class BookmanagerApplication {
```

```java
@EntityListeners(value = AuditingEntityListener.class)
public class Book implements Auditable {
    ...
    @CreatedDate
    private LocalDateTime createdAt;

    @LastModifiedDate
    private LocalDateTime updatedAt;
    ...
}
```

1. User, Book, UserHistory class에 @EntityListeners 의 value 값을 **AuditingEntityListener**로 변경.
2. createdAt 메서드에 @CreatedDate,
3. updatedAt 메서드에 @LastModifiedDate annotation 추가.

이렇게 간단하게 Jpa에서 자동으로 제공해주는 Listener을 사용할 수 있음.

---

하지만 또 User, Book, UserHistory 등 모든 클래스의 메서드에 어노테이션을 추가해야하기 때문에, 아래의 방법을 사용.

BaseEntity 클래스를 아래와 같이 생성.

```java
@Data
@MappedSuperclass // 해당 클래스의 필드를 상위 entity에 컬럼으로 사용하겠다
@EntityListeners(value = AuditingEntityListener.class)
public class BaseEntity {

    @CreatedDate
    private LocalDateTime createdAt;

    @LastModifiedDate
    private LocalDateTime updatedAt;
}
```

User, Book, UserHistory 등의 클래스에 createdAt, updatedAt을 지우고 extends BaseEntity 시키고

```java
public class User extends BaseEntity implements Auditable {
```

```java
@EntityListeners(value = AuditingEntityListener.class)
```

는 BaseEntity가 제공하고 있기 때문에 지움.

@Data의 warning mark를 지우기위하여 아래의 어노테이션을 추가함.

```java
@ToString(callSuper = true)
@EqualsAndHashCode(callSuper = true)
```

가장 많이 쓰이는 방식은, BaseEntity class를 만들어서 @EntityListeners 처리하고  
다른 클래스들이 이것을 상속받는 방법으로 Listener 처리함.
