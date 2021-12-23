package com.fastcampus.jpa.bookmanager.repository;

import com.fastcampus.jpa.bookmanager.domain.Book;
import com.fastcampus.jpa.bookmanager.domain.Publisher;
import com.fastcampus.jpa.bookmanager.domain.Review;
import com.fastcampus.jpa.bookmanager.domain.User;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
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

        publisherRepository.save(publisher); // 영속화

        book.setPublisher(publisher); // 연관관계 만들기
        bookRepository.save(book);

        // publisher.getBooks().add(book);
        publisher.addBook(book); // -> 더 가독성있는 코드를 위하여 메소드를 추가해줌
        publisherRepository.save(publisher);

        System.out.println("books : " + bookRepository.findAll());
        System.out.println("publishers : " + publisherRepository.findAll());
    }


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
