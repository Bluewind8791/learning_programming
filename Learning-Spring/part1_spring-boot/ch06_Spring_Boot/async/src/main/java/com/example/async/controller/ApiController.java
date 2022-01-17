package com.example.async.controller;

import java.util.concurrent.CompletableFuture;

import com.example.async.service.AsyncService;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import lombok.extern.slf4j.Slf4j;


@Slf4j
@RestController
@RequestMapping("/api")
public class ApiController {
    
    @Autowired
    private AsyncService asyncService;


    @GetMapping("/hello")
    public CompletableFuture hello() {
        // asyncService.hello();
        log.info("completable future init");
        return asyncService.run();
    }
}
