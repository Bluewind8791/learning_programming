package com.demo.config;

import com.demo.domain.User;
import com.demo.repository.UserRepository;

import org.springframework.boot.CommandLineRunner;
import org.springframework.stereotype.Component;

import lombok.RequiredArgsConstructor;

@Component
@RequiredArgsConstructor
public class DBInit implements CommandLineRunner {

    private final UserRepository userRepository;

    @Override
    public void run(String... args) throws Exception {
        userRepository.save(User.builder()
            .email("email")
            .build()
        );
    }

}
