package com.fastcampus.jpa.bookmanager.service;

import com.fastcampus.jpa.bookmanager.repository.UserRepository;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
public class UserServiceTest {

    @Autowired
    private UserService userService;

    @Autowired
    private UserRepository userRepository;

    @Test
    void testPut() {
        userService.put();

        // System.out.println(">>> " + userRepository.findByEmail("newuser@email.com"));

        userRepository.findAll().forEach(System.out::println);
    }
}
