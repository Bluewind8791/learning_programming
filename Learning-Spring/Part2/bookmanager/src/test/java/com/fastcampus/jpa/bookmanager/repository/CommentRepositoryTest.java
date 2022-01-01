package com.fastcampus.jpa.bookmanager.repository;

import java.time.LocalDateTime;

import javax.persistence.EntityManager;

import com.fastcampus.jpa.bookmanager.domain.Comment;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.transaction.annotation.Transactional;

@SpringBootTest
public class CommentRepositoryTest {

    @Autowired
    private CommentRepository commentRepository;

    @Autowired
    private EntityManager entityManager;

    @Test
    @Transactional
    void commentTest() {
        Comment comment = commentRepository.findById(3L).get();
        // comment.setComment("It is not good");
        comment.setCommentedAt(LocalDateTime.now());

        commentRepository.saveAndFlush(comment);

        entityManager.clear();

        System.out.println(commentRepository.findById(3L).get()); // cache를 사용하여 결과깂을 도출
    }

    @Test
    @Transactional
    void commentTest2() {
        Comment comment = new Comment();
        comment.setComment("It is not good");

        commentRepository.saveAndFlush(comment);

        // entityManager.clear();

        System.out.println(comment);

        commentRepository.findAll().forEach(System.out::println);
    }
}



