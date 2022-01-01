package com.fastcampus.jpa.bookmanager.service;

import java.util.List;

import com.fastcampus.jpa.bookmanager.domain.Comment;
import com.fastcampus.jpa.bookmanager.repository.CommentRepository;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

@Service
public class CommentService {
    
    @Autowired
    private CommentRepository commentRepository;

    @Transactional
    public void init() {
        for (int i=0; i<10; i++) {
            Comment comment = new Comment();
            comment.setComment("init comment");

            commentRepository.save(comment);
        }
    }

    @Transactional(readOnly = true)
    public void updateSomething() {
        List<Comment> comments = commentRepository.findAll();

        for(Comment comment : comments) {
            comment.setComment("update comment");

            commentRepository.save(comment);
        }
    }

    @Transactional
    public void insertSomething() {
        // Comment comment = new Comment();
        Comment comment = commentRepository.findById(1L).get(); //영속성 컨텍스트로 관리되고 있는 아이
        comment.setComment("insert comment");

        // commentRepository.save(comment);
    }
}
