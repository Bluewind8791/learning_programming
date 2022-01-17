# CRUD - Create, Read, Update, Delete

## Simple Jpa Repository

### ■ findAll()

```java
userRepository.save(new User()); // save() 
userRepository.findAll().forEach(System.out::println);
List<User> users = userRepository.findAll(Sort.by(Direction.DESC, "name"));
users.forEach(System.out::println);

User user1 = new User("Jack", "jack@email");
User user2 = new User("Samuel", "samu@email");
userRepository.saveAll(Lists.newArrayList(user1, user2));
List<User> users = userRepository.findAll();
users.forEach(System.out::println);
```

table의 전체값을 가져오는 메소드

---

### ■ findById()

```java
Optional<User> user = userRepository.findById(1L);
System.out.println(user);
```

의미 그대로 Id(PK)값을 통하여 DB에서 찾음.

---

### ■ flush()

```java
userRepository.save(new User("name", "email"));
userRepository.flush();
// == saveAndFlush(new User("name", "email"));
userRepository.findAll().forEach(System.out::println);
```

수동으로 영속화를 시킴. 자세한 내용은 뒤의 영속화 부분에서...

---

### ■ count()

```java
long count = userRepository.count();
System.out.println(count);
```

DB의 수를 return 한다.

---

### ■ existsById()

```java
boolean exits = userRepository.existsById(1L);
System.out.println(exits);
```

해당 id가 존재하는지 boolean으로 return 한다.

---

### ■ delete

```java
userRepository.delete(userRepository.findById(1L).orElseThrow(RuntimeException::new));
```

entity must not be null 이여야 하며, 해당 id에 해당하는 db값을 삭제한다.

---

### ■ deleteById(index)

```java
userRepository.deleteById(1L);
```

select query -> delete

---

### ■ deleteAll()

```java
userRepository.deleteAll();
```

findAll()후에 각 element를 delete 한다.

---

### ■ deleteAllInBatch()

```java
userRepository.deleteAllInBatch(userRepository.findAllById(Lists.newArrayList(1L, 3L)));
```

query를 만들고 delete 실행, 쿼리 한번만 실행

---
---

## Page

```java
Page<User> users= userRepository.findAll(PageRequest.of(1, 3));

System.out.println("page : " + users);
System.out.println("total elements : " + users.getTotalElements());
System.out.println("total pages : " + users.getTotalPages());
System.out.println("number of elements : " + users.getNumberOfElements()); // 현재 가져온 elements 수
System.out.println("sort : " + users.getSort());
System.out.println("size : " + users.getSize());

users.getContent().forEach(System.out::println);
```

---

## Example (searching)

```java
ExampleMatcher matcher = ExampleMatcher.matching()
    .withIgnorePaths("name") // name은 매칭안함
    .withMatcher("email", GenericPropertyMatchers.endsWith()); // email 항목의 끝부분만 매치

Example<User> example = Example.of(new User("ma", "fastcam.com"), matcher);
userRepository.findAll(example).forEach(System.out::println);
```

withIgnorePaths()에 name을 넣었기때문에 "ma"는 무시되며,  
fastcam.com으로 끝나는 email db를 조회함.

``` java
User user = new User();
user.setEmail("slow");

ExampleMatcher matcher = ExampleMatcher.matching().withMatcher("email", GenericPropertyMatchers.contains());
Example<User> example = Example.of(user, matcher);

userRepository.findAll(example).forEach(System.out::println);
```

email 항목에서 slow라는 문자열이 있는지 매칭함.

---

## Save

```java
userRepository.save(new User("Ben", "ben@email.com"));

User user = userRepository.findById(1L).orElse(null);
user.setEmail("updated@email.com");

userRepository.save(user);
```

영속화를 시킴. 해당 내용은 Persistence에 자세하게 다룬다.
