package com.fastcampus.jpa.bookmanager.repository;


import com.fastcampus.jpa.bookmanager.domain.Gender;
import com.fastcampus.jpa.bookmanager.domain.User;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.data.domain.PageRequest;
import org.springframework.data.domain.Sort;
import org.springframework.data.domain.Sort.Order;
import org.springframework.transaction.annotation.Transactional;

import lombok.extern.slf4j.Slf4j;


@Slf4j
@SpringBootTest
class UserRepositoryTest {

    @Autowired
    private UserRepository userRepository;

    @Test
    @Transactional
    void crud() { // create, read, update, delete
        
        User user = userRepository.findById(1L).orElse(null);
        user.setEmail("updated@email.com");
        userRepository.save(user);
    }

    @Test
    void sortingTest() {
        log.info("findFirstByName WithSortParams : {}", 
            userRepository.findFirstByName("ben", Sort.by(Order.desc("id"))));
        log.info("findFirstByName WithSortParams : {}", 
            userRepository.findFirstByName("ben", Sort.by(Order.desc("id"), Order.asc("email"))));
    }

    @Test
    void pagingTest() {
        log.info("findByName with paging : {}",
            userRepository.findByName("ben", PageRequest.of(0, 1, Sort.by(Order.desc("id")))));
    }


    @Test
    void insertAndUpdateTest() {
        User user = new User();
        user.setName("ben");
        user.setEmail("ben@email.com");
        userRepository.save(user);

        User user2 = userRepository.findById(1L).orElseThrow(RuntimeException::new);
        user2.setName("beeeeeeen");

        userRepository.save(user2);
    }

    @Test
    void enumTest() {
        User user = userRepository.findById(1L).orElseThrow(RuntimeException::new);
        user.setGender(Gender.MALE);

        userRepository.save(user);

        userRepository.findAll().forEach(System.out::println);

        System.out.println(userRepository.findRawRecord().get("gender"));
    }
}

