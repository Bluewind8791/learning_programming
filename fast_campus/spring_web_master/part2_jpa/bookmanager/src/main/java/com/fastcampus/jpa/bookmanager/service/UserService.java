package com.fastcampus.jpa.bookmanager.service;

import javax.persistence.EntityManager;
import javax.transaction.Transactional;

import com.fastcampus.jpa.bookmanager.domain.User;
import com.fastcampus.jpa.bookmanager.repository.UserRepository;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class UserService {

    @Autowired
    private EntityManager entityManager;

    @Autowired
    private UserRepository userRepository;

    @Transactional
    public void put() {
        User user = new User();
        user.setName("new user");
        user.setEmail("newuser@email.com");        

        entityManager.persist(user);
        // entityManager.detach(user);

        user.setName("newUserAfterPersist");
        entityManager.merge(user);
        // entityManager.flush();
        // entityManager.clear();

        User user1 = userRepository.findById(1L).get();
        entityManager.remove(user1);
    }
}
