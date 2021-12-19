package com.fastcampus.jpa.bookmanager.service;

import javax.persistence.EntityManager;
import javax.transaction.Transactional;

import com.fastcampus.jpa.bookmanager.domain.User;
import com.fastcampus.jpa.bookmanager.repository.UserRepository;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
@Transactional
public class EntityManagerTest {
    
    @Autowired
    private EntityManager entityManager;

    @Autowired
    private UserRepository userRepository;

    @Test
    void entityManagerTest() {
        System.out.println(entityManager.createQuery("select u from User u").getResultList());
    }

    @Test
    void cacheFindTest() {
        System.out.println(userRepository.findById(1L).get());
        System.out.println(userRepository.findById(1L).get());
        System.out.println(userRepository.findById(1L).get());
    }

    @Test
    void cacheFindTest2() {
        User user = userRepository.findById(1L).get();
        user.setName("marrrrrtin");
        userRepository.save(user);

        System.out.println("-----------------------------------------");

        user.setEmail("martinnnnnn@fastcampus.com");
        userRepository.save(user);

        System.out.println(">>> " + userRepository.findAll());  // select * from user
    }
}
