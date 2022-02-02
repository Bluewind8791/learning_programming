package com.sp.fc.web.controller;

import static org.junit.jupiter.api.Assertions.assertEquals;

import com.sp.fc.web.test.WebIntegrationTest;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.web.client.TestRestTemplate;
import org.springframework.http.ResponseEntity;

public class AuthorityBasicTest extends WebIntegrationTest {

    TestRestTemplate client;

    @DisplayName("1. greeting message test")
    @Test
    void test_1() {
        client = new TestRestTemplate("user1", "1111");
        ResponseEntity<String> response = client.getForEntity(uri("/greeting"), String.class);

        assertEquals("hello", response.getBody());
        System.out.println(response.getBody());
    }

    @DisplayName("2. greeting message test")
    @Test
    void test_2() {
        client = new TestRestTemplate("user1", "1111");
        ResponseEntity<String> response = client.getForEntity(uri("/greeting/ben"), String.class);

        assertEquals("hello ben", response.getBody());
        System.out.println(response.getBody());
    }

}
