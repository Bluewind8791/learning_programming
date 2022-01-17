package com.sp.fc.web.controller;

import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HomeController {
    
    // @GetMapping("/greeting")
    // public String greeting() {
    //     return "greeting!";
    // }

    @PostMapping("/greeting")
    public String greeting(@RequestBody String name) {
        return "post "+name;
    }
}
