package com.swagger.controller;

import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import com.swagger.config.SpringDocApiResponse;

import io.swagger.v3.oas.annotations.Operation;
import io.swagger.v3.oas.annotations.tags.Tag;


@Tag(name = "Hello Controller", description = "테스트용 Hello 컨트롤러")
@RestController
public class HelloController {

    @GetMapping("/hello")
    @SpringDocApiResponse
    @Operation(summary = "hello summary", description = "hello description")
    public ResponseEntity<String> hello() {
        return ResponseEntity.ok("hello Swagger!");
    }

}
