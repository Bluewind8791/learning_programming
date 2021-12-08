package com.fastcampus.jpa.bookmanager.repository;


import com.fastcampus.jpa.bookmanager.domain.User;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.data.domain.Example;
import org.springframework.data.domain.ExampleMatcher;
import org.springframework.data.domain.ExampleMatcher.GenericPropertyMatchers;
import org.springframework.transaction.annotation.Transactional;

@SpringBootTest
class UserRepositoryTest {

    @Autowired
    private UserRepository userRepository;

    @Test
    @Transactional
    void crud() { // create, read, update, delete
        
        userRepository.save(new User("Ben", "ben@email.com"));

        User user = userRepository.findById(1L).orElse(null);
        user.setEmail("updated@email.com");

        userRepository.save(user);
    }
}

