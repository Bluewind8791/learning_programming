package com.fastcampus.jpa.bookmanager.service;

import com.fastcampus.jpa.bookmanager.domain.Book;
import com.fastcampus.jpa.bookmanager.repository.AuthorRepository;
import com.fastcampus.jpa.bookmanager.repository.BookRepository;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;


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

    @Test
    void isolationTest() {
        Book book = new Book();
        book.setName("JPA COURSE");

        bookRepository.save(book);

        bookService.get(1L);
        System.out.println(">>> " + bookRepository.findAll());
    }
}
