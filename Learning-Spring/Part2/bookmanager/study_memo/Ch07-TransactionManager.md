# Transaction Manager

## JPA에서 Transaction 활용하기

### Transaction 이란?

데이터베이스에서 사용하며, 명령어의 논리적인 묶음.

예를들어 물건을 구매하는 행위에서는 사용자가 결제하는 행위와 물건이 구입되는 행위가 동시에 일어남.
사용자가 물건을 구매해서 결제를 하고 payment 테이블에 데이터가 insert되었는데,
물건이 구입되는 테이블에 insert하다가 오류가 발생하면, 결제는 되었지만 물건을 받지못하는 케이스가 발생할 수 있다.
그래서 결제와 주문은 논리적으로 하나의 트랜잭션으로 처리하도록 함.

---

### Transaction 특성

### **ACID**

- Automicity(원자성)  : 부분적인 성공을 허용하지 않음.
- Consistency(일관성) : 송금에 성공하려면 계좌의 잔액도 0보다 커야함. 데이터간에 정확성을 맞추는 작업.
- Isolation(독립성)   : 다른 트랜잭션으로부터 독립성을 가지게 됨.  
- Durability(지속성)  : 돈을 송금했다면 친구의 통장에는 지속적으로 +가 되어야한다.

---

### **@Transactional**

Book service와 테스트 클래스를 아래와 같이 생성.

```java
@Service
public class BookService {
    @Autowired
    private BookRepository bookRepository;
    @Autowired
    private AuthorRepository authorRepository;

    @Transactional // ★
    public void putBookAndAuthor() {
        Book book = new Book();
        book.setName("Starting JPA Book");
        bookRepository.save(book);

        Author author = new Author();
        author.setName("martin");
        authorRepository.save(author);

        throw new RuntimeException("DB Error : No DB commit!!");
    }
}
```

```java
@SpringBootTest
public class BookServiceTest {
    @Autowired
    private BookService bookService;
    @Autowired
    private BookRepository bookRepository;
    @Autowired
    private AuthorRepository authorRepository;

    @Test
    void transactionTest() {
        try {
            bookService.putBookAndAuthor();
        } catch (RuntimeException e) {
            System.out.println(">>> " + e.getMessage());
        }
        System.out.println(">>> books : " + bookRepository.findAll());
        System.out.println(">>> authors : " + authorRepository.findAll());
    }
}
```

고의적으로 service 클래스에 exception 처리를 하여서 에러를 발생시켰다. 이렇게 하면 Transactional 처리를 한 결과값과 처리하지 않은 결과값이 상반되는데,  

@Transactional 하지않은 경우에는

> books : [Book(super=BaseEntity(createdAt=2021-12-19T19:51:19.235446, updatedAt=2021-12-19T19:51:19.235446), id=1, Name=Starting JPA Book, category=null, authorId=null)]  
> authors : [Author(super=BaseEntity(createdAt=2021-12-19T19:51:19.392227, updatedAt=2021-12-19T19:51:19.392227), id=1, name=martin, country=null)]

에러에도 불구하고 결과값이 여전히 유효하게 나오지만.

@Transactional 처리를 하고나면

> books : []  
> authors : []

로 결과값이 나오지 않는다.  
이는 ACID의 트랜잭션의 **All or Nothing** 특성처럼, 일관성있게 처리됨을 알 수 있다.

- RuntimeException을 Exception으로 바꾸면, Transactional 을 처리를 해도 결과값이 나온다.

- RuntimeException은 transaction안에서 발생하면 반용 내용이 rollback되고, checked exception은 transaction 내에서 발생하더라도 반영 내용이 rollback되지 않고 commit 되어버린다.

---

put() 이라는 메소드를 만들어서, 트랜잭션이 걸린 putBookAndAuthor를 호출해보자.

```java
@Service
public class BookService {
    @Autowired
    private BookRepository bookRepository;
    @Autowired
    private AuthorRepository authorRepository;

    public void put() {
        this.putBookAndAuthor();
    }

    @Transactional
    void putBookAndAuthor() {
        Book book = new Book();
        book.setName("Starting JPA Book");

        bookRepository.save(book);

        Author author = new Author();
        author.setName("martin");

        authorRepository.save(author);

        throw new RuntimeException("DB Error : No DB commit!!");
    }
}
```

```java
@SpringBootTest
public class BookServiceTest {
    @Autowired
    private BookService bookService;
    @Autowired
    private BookRepository bookRepository;
    @Autowired
    private AuthorRepository authorRepository;

    @Test
    void transactionTest() throws Exception {
        try {
            // bookService.putBookAndAuthor();
            bookService.put();
        } catch (RuntimeException e) {
            System.out.println(">>> " + e.getMessage());
        }
        
        System.out.println(">>> books : " + bookRepository.findAll());
        System.out.println(">>> authors : " + authorRepository.findAll());
    }
}
```

put이라는 메소드에 진입하는 순간 이 bean 내부로 들어왔으며,  
진입한 이후에 bean 내부에있는 다른 메소드를 호출하게되면 **트랜잭션 어노테이션을 읽지 않아 동작하지 않음.**

---
---

## isolation()

### ■ 트랜잭션 격리 4단계

단계가 아래로 내려갈수록 격리단계가 강력해지며, 데이터의 정확성을 보장해주지만, 동시에 동시처리하는 성능이 떨어지며, 위쪽으로 올라갈수록 성능은 올라가지만 일부 데이터를 정확성을 보장하지못하는 경우가 간혹 생김.

- **DEFAULT** :
  - DB의 default 격리단계.
  - My-SQL의 경우에는 default 단계가 'REAPEATABLE_READ' 단계이다.
- 1단계 **READ_UNCOMMITTED** :
  - 아직 commit 되지 않은 데이터를 읽을 수 있는 단계. (dirty read)
- 2단계 **READ_COMMITTED** :
  - 1단계에서 발생하였던 dirty read의 현상이 없어지며, 커밋과 롤백에 맞춰서 의도한대로 로직이 동작함.
  - 하지만 update나 insert 작업을 하지않았는데, 반복적으로 조회를 하는데 중간에 값이 변경되어버리는 경우가 발생함. 이런 경우를 **unreapeatable read**라고 하며, 조작은 하지 않았지만 트랜잭션 내에서 조회값이 달라질수도 있는 현상이다.
- 3단계 **REPEATABLE_READ** :
  - Unreapeatable read 상태를 해결하기 위하여 나온 단계. 즉 반복적으로 조회를 하더라도 항상 같은 값이 도출됨.
  - 조회하는 도중에 상태값을 update하고 commit 하더라도, 별도의 스냅샷으로 커밋된 데이터를 직접 가져오는것이 아니라, 트랜잭션이 시작할때에 조회했던 데이터를 별도로 저장하고 있다가 이 트랜잭션이 끝나기 전까진 이 정보를 지속적으로 return 하게 됨.
  - 여기서도 문제가 발생하는데, 트랜잭션 내에서 한개의 레코드를 처리하는데 실제로는 두개의 레코드가 처리될 수 있따. 이렇게 경우에 따라서 데이터가 안보이는데 처리되는것을 **팬텀 리드**라는 현상이라 한다.
- 4단계 **SERIALIZABLE** :
  - 역시나 팬텀 리드현상을 해결하기 위하여 나온 단계.
  - commit이 일어나지않은 트랜잭션이 존재하게되면 lock을 통하여 waiting을 하게됨. 그래서 commit이 실행되어야만 추가적인 로직 진행을 하게된다.
  - 데이터의 정확성이 거의 100%로 맞춰지게됨. 하지만 waiting 때문에 성능에는 좋지못한 격리 수준.

---
---

## 트랜잭션 전파 propagation()

propagation:  the act of producing a new plant from a parent plant

- REQUIRED :
  - default 값.
  - 만약 기존의 사용하게되던 트랜잭션이있다면 그 트랜잭션을 사용하고, 없다면 새로운 트랜잭션을 생성해서 사용한다.
  - save 메소드가 이 REQUIRED로 적용되어있음.

- SUPPORT
- REQUIRES_NEW
- NOT_SUPPORTED
- NEVER
- NESTED
