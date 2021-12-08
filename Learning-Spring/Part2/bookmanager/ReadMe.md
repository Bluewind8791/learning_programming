# CRUD - Create, Read, Update, Delete

```java
// findAll() table의 전체값을 가져오는 메소드
userRepository.save(new User()); // save() 
userRepository.findAll().forEach(System.out::println);
List<User> users = userRepository.findAll(Sort.by(Direction.DESC, "name"));
users.forEach(System.out::println);

User user1 = new User("Jack", "jack@email");
User user2 = new User("Samuel", "samu@email");
userRepository.saveAll(Lists.newArrayList(user1, user2));
List<User> users = userRepository.findAll();
users.forEach(System.out::println);


// findById()
Optional<User> user = userRepository.findById(1L);
System.out.println(user);


// flush()
userRepository.save(new User("name", "email"));
userRepository.flush();
// == saveAndFlush(new User("name", "email"));
userRepository.findAll().forEach(System.out::println);


// count() - DB의 수 return
long count = userRepository.count();
System.out.println(count);


// existsById - 1 index가 존재하는지 boolean으로 return
boolean exits = userRepository.existsById(1L);
System.out.println(exits);


// delete() : entity must not be null
userRepository.delete(userRepository.findById(1L).orElseThrow(RuntimeException::new));


// deleteById(index) : select query -> delete
userRepository.deleteById(1L);


// deleteAll()
userRepository.deleteAll();


// deleteAllInBatch()
userRepository.deleteAllInBatch(userRepository.findAllById(Lists.newArrayList(1L, 3L)));

```




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



## Example (searching)

```java
ExampleMatcher matcher = ExampleMatcher.matching()
    .withIgnorePaths("name") // name은 매칭안함
    .withMatcher("email", GenericPropertyMatchers.endsWith()); // email 항목의 끝부분만 매치

Example<User> example = Example.of(new User("ma", "fastcam.com"), matcher);
userRepository.findAll(example).forEach(System.out::println);
```

withIgnorePaths()에 name을 넣었기때문에 "ma"는 무시되며, fastcam.com으로 끝나는 email db를 조회함.


``` java
User user = new User();
user.setEmail("slow");

ExampleMatcher matcher = ExampleMatcher.matching().withMatcher("email", GenericPropertyMatchers.contains());
Example<User> example = Example.of(user, matcher);

userRepository.findAll(example).forEach(System.out::println);
```
email 항목에서 slow라는 문자열이 있는지 매칭함.


## Save

```java
userRepository.save(new User("Ben", "ben@email.com"));

User user = userRepository.findById(1L).orElse(null);
user.setEmail("updated@email.com");

userRepository.save(user);
```