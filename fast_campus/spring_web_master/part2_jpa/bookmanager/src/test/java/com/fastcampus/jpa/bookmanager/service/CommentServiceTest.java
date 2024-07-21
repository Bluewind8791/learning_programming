package com.fastcampus.jpa.bookmanager.service;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
public class CommentServiceTest {

    @Autowired
    private CommentService commentService;

    @Test
    void commentTest() {
        commentService.init();

        // commentRepository.findAll().forEach(System.out::println);

        // commentService.updateSomething();
        commentService.insertSomething();
    }
}
