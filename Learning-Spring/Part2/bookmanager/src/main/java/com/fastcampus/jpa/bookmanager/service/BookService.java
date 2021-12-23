package com.fastcampus.jpa.bookmanager.service;

import javax.persistence.EntityManager;

import com.fastcampus.jpa.bookmanager.domain.Book;
// import com.fastcampus.jpa.bookmanager.repository.AuthorRepository;
import com.fastcampus.jpa.bookmanager.repository.BookRepository;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;


@Service
public class BookService {
    
    @Autowired
    private BookRepository bookRepository;
    // @Autowired
    // private AuthorRepository authorRepository;
    @Autowired
    private EntityManager entityManager;
    @Autowired
    private AuthorService authorService;

    public void put() {
        this.putBookAndAuthor();
    }

    @Transactional(propagation = Propagation.NESTED)
    void putBookAndAuthor() {
        Book book = new Book();
        book.setName("Starting JPA Book");
        bookRepository.save(book);

        try {
            authorService.putAuthor();
        } catch (RuntimeException e) {
        }
        
        // throw new RuntimeException("오류가 발생하였습니다. transaction은 어떻게 될까요?");

        // Author author = new Author();
        // author.setName("martin");
        // authorRepository.save(author);

        // throw new RuntimeException("DB Error : No DB commit!!");
    }

    @Transactional(isolation = Isolation.SERIALIZABLE)
    public void get(Long id) {
        System.out.println(">>> " + bookRepository.findById(id));
        System.out.println(">>> " + bookRepository.findAll());

        entityManager.clear();

        System.out.println(">>> " + bookRepository.findById(id));
        System.out.println(">>> " + bookRepository.findAll());

        bookRepository.update();

        entityManager.clear();

        // Book book = bookRepository.findById(id).get();
        // book.setName("Will be changed?");
        // bookRepository.save(book);
    }
}
