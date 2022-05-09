package com.demo.controller;

import com.demo.repository.UserRepository;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import lombok.RequiredArgsConstructor;



@RestController
@RequiredArgsConstructor
public class HomeController {

    private final UserRepository userRepository;

    @GetMapping(value = {"/", ""})
    public String getUserInfo() {
        return userRepository.findAll().toString();
    }

}
