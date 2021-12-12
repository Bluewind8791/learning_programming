package com.fastcampus.jpa.bookmanager.repository;



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
        
        userRepository.save(new User("Ben", "ben@email.com"));

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
}

