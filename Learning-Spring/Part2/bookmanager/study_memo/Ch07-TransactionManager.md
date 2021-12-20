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

---

RuntimeException을 Exception으로 바꾸면, Transactional 을 처리를 해도 결과값이 나온다.

RuntimeException은 transaction안에서 발생하면 반용 내용이 rollback되고,  
checked exception은 transaction 내에서 발생하더라도 반영 내용이 rollback되지 않고 commit 되어버린다.
