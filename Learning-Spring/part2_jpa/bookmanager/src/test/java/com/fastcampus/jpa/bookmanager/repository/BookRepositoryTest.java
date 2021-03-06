package com.fastcampus.jpa.bookmanager.repository;

import com.fastcampus.jpa.bookmanager.domain.Book;
import com.fastcampus.jpa.bookmanager.domain.Publisher;
import com.fastcampus.jpa.bookmanager.domain.Review;
import com.fastcampus.jpa.bookmanager.domain.User;
import com.fastcampus.jpa.bookmanager.repository.dto.BookStatus;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.data.domain.PageRequest;
import org.springframework.transaction.annotation.Transactional;

@SpringBootTest
public class BookRepositoryTest {
    
    @Autowired
    private BookRepository bookRepository;

    @Autowired
    private PublisherRepository publisherRepository;

    @Autowired
    private ReviewRepository reviewRepository;

    @Autowired
    private UserRepository userRepository;

    @Test
    void bookTest() {
        Book book = new Book();
        book.setName("Jpa Study Package");
        book.setAuthorId(1L);
        // book.setPublisherId(1L);
        
        bookRepository.save(book);

        System.out.println(bookRepository.findAll());
    }

    @Test
    @Transactional
    void bookRelationTest() {
        givenBookAndReview();

        User user = userRepository.findByEmail("martin@fastcampus.com");

        System.out.println("Review : " + user.getReviews());
        System.out.println("Book : " + user.getReviews().get(0).getBook());
        System.out.println("Publisher : " + user.getReviews().get(0).getBook().getPublisher());
    }

    @Test
    @Transactional // lazy initialization exception
    void bookCascadeTest() {
        Book book = new Book();
        book.setName("JPA 초격차 패키지");

        bookRepository.save(book); // 영속화

        Publisher publisher = new Publisher();
        publisher.setName("FastCampus");

        book.setPublisher(publisher); // 연관관계 만들기
        bookRepository.save(book);

        // publisher.getBooks().add(book);
        publisher.addBook(book); // -> 더 가독성있는 코드를 위하여 메소드를 추가해줌
        publisherRepository.save(publisher);

        // System.out.println("books : " + bookRepository.findAll());
        // System.out.println("publishers : " + publisherRepository.findAll());

        // Book book1 = bookRepository.findById(1L).get();
        // book1.getPublisher().setName("슬로우캠퍼스");
        // bookRepository.save(book1);

        // System.out.println("revised publishers : " + publisherRepository.findAll());

        // delete
        // Book book2 = bookRepository.findById(1L).get();
        // bookRepository.delete(book2);
        // bookRepository.deleteById(1L); 위의 두줄과 동일한 효과

        Book book3 = bookRepository.findById(1L).get();
        book3.setPublisher(null);
        bookRepository.save(book3);

        System.out.println(">>> books : " + bookRepository.findAll());
        System.out.println(">>> publishers : " + publisherRepository.findAll());
        System.out.println(">>> book3-publisher : " + bookRepository.findById(1L).get().getPublisher());
    }

    @Test
    void bookRemoveCascadeTest() {
        bookRepository.deleteById(1L);

        System.out.println("books : " + bookRepository.findAll());
        System.out.println("publishers : " + publisherRepository.findAll());

        bookRepository.findAll().forEach(book -> System.out.println(book.getPublisher()));
    }

    @Test
    void softDelete() {
        bookRepository.findAll().forEach(System.out::println);
        System.out.println(">>> " +bookRepository.findById(3L));

        // bookRepository.findByCategoryIsNull().forEach(System.out::println);
        // bookRepository.findAllByDeletedFalse().forEach(System.out::println);
        // bookRepository.findByCategoryIsNullAndDeletedFalse().forEach(System.out::println);
    }


    @Test
    void queryTest() {
        
        // System.out.println(">>> findByCategoryIsNullAndNameEqualsAndCreatedAtGreaterThanEqualAndUpdatedAtGreaterThanEqual : " 
        //     + bookRepository.findByCategoryIsNullAndNameEqualsAndCreatedAtGreaterThanEqualAndUpdatedAtGreaterThanEqual(
        //         "JPA 초격차 패키지", 
        //         LocalDateTime.now().minusDays(1L), 
        //         LocalDateTime.now().minusDays(1L)
        //     ));

        // System.out.println(">>> findByNameRecently : " 
        //     + bookRepository.findByNameRecently(
        //         "JPA 초격차 패키지", 
        //         LocalDateTime.now().minusDays(1L), 
        //         LocalDateTime.now().minusDays(1L)
        //     ));

        // System.out.println(bookRepository.findBookNameAndCategory());
        // bookRepository.findBookNameAndCategory().forEach(tuple -> {System.out.println(tuple.get(0) + " : " + tuple.get(1));});
        // bookRepository.findBookNameAndCategory().forEach(b -> {System.out.println(b.getName() + " : " + b.getCategory());});

        bookRepository.findBookNameAndCategory(PageRequest.of(1, 1)).forEach(
            BookNameAndCategory -> System.out.println(BookNameAndCategory.getName() + " : " + BookNameAndCategory.getCategory())
        );

        bookRepository.findBookNameAndCategory(PageRequest.of(0, 1)).forEach(
            BookNameAndCategory -> System.out.println(BookNameAndCategory.getName() + " : " + BookNameAndCategory.getCategory())
        );
    }

    @Test
    void nativeQueryTest() {
        // bookRepository.findAll().forEach(System.out::println);
        // bookRepository.findAllCustom().forEach(System.out::println);

        // List<Book> books = bookRepository.findAll();
        
        // for(Book book : books) {
        //     book.setCategory("IT 전문서");
        // }

        // bookRepository.saveAll(books);
        // System.out.println(bookRepository.findAll());

        System.out.println("affected rows : " + bookRepository.updateCategories());
        // System.out.println(bookRepository.findAllCustom());
        bookRepository.findAllCustom().forEach(System.out::println);

        System.out.println(bookRepository.showTables());
    }

    @Test
    void converterTest() {
        bookRepository.findAll().forEach(System.out::println);

        Book book = new Book();
        book.setName("또다른 IT 전문서적");
        book.setStatus(new BookStatus(200));

        bookRepository.save(book);

        System.out.println(">>> " + bookRepository.findRawRecord().values());
    }

// ----------------------------------------------------------------------------------------

    private void givenBookAndReview() {
        givenReview(givenUser(), givenBook());
    }

    private User givenUser() {
        return userRepository.findByEmail("martin@fastcampus.com");
    }

    private Book givenBook() {
        Book book = new Book();
        book.setName("JPA BOOK");
        book.setPublisher(givenPublisher());

        return bookRepository.save(book);
    }

    private Publisher givenPublisher() {
        Publisher publisher = new Publisher();
        publisher.setName("FastCampus Publisher");
        return publisherRepository.save(publisher);
    }

    private void givenReview(User user, Book book) {
        Review review = new Review();
        review.setTitle("Review Title");
        review.setContent("It is book review.");
        review.setScore(5.0f);
        review.setUser(user);
        review.setBook(book);

        reviewRepository.save(review);
    }
}
