package com.example.exception.controller;

import javax.validation.Valid;

import com.example.exception.dto.User;

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.MethodArgumentNotValidException;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;


@RestController
@RequestMapping("/api/user")
public class ApiController {
    
    @GetMapping("") // required = false는 ?name=1234 로 값이 들어가있지 않아도 실행시키게 함, default는 true
    public User get(@RequestParam(required = false) String name, @RequestParam(required = false) Integer age) {
        User user = new User();
        user.setName(name);
        user.setAge(age);

        int a = 10 + age;
        System.out.println(a);

        return user;
    }

    @PostMapping("")
    public User post(@Valid @RequestBody User user) {
        System.out.println(user);
        return user;
    }

    // 우선순위가 높음, 이곳을 타게되면 글로벌 exception handler는 타지않음
    @ExceptionHandler(value = MethodArgumentNotValidException.class)
    public ResponseEntity methodArgumentNotValidException(MethodArgumentNotValidException e) {
        System.out.println("Api Controller Exception Handler");
        return ResponseEntity.status(HttpStatus.BAD_REQUEST).body(e.getMessage());
    }
}
