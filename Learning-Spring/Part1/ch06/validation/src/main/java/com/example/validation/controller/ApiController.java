package com.example.validation.controller;

import javax.validation.Valid;

import com.example.validation.dto.User;

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.BindingResult;
import org.springframework.validation.FieldError;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/api")
public class ApiController {


    // valid annotation을 붙여서, 해당 object를 검사
    @PostMapping("/user")
    public ResponseEntity<Object> user(@Valid @RequestBody User user, BindingResult bindingResult) { 

        if (bindingResult.hasErrors()) {
            StringBuilder sb = new StringBuilder();
            bindingResult.getAllErrors().forEach(objectError -> {
                FieldError field = (FieldError) objectError;
                String message = objectError.getDefaultMessage();
                System.out.println("field : " + field.getField());
                System.out.println(message);
                
                sb.append("field : " + field.getField());
                sb.append("message : " + message);
            });
            
            return ResponseEntity.status(HttpStatus.BAD_REQUEST).body(sb.toString());
        }

        // logic

        System.out.println(user);
        return ResponseEntity.ok(user);
    }// end of user





}// end of class
