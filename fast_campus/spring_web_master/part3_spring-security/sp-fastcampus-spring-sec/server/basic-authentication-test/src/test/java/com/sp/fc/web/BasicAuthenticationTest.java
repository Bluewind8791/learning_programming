package com.sp.fc.web;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

import java.util.Base64;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.context.SpringBootTest.WebEnvironment;
import org.springframework.boot.test.web.client.TestRestTemplate;
import org.springframework.boot.web.server.LocalServerPort;
import org.springframework.http.HttpEntity;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpMethod;
import org.springframework.http.ResponseEntity;
import org.springframework.web.client.HttpClientErrorException;
import org.springframework.web.client.RestTemplate;

@SpringBootTest(webEnvironment = WebEnvironment.RANDOM_PORT)
public class BasicAuthenticationTest {

    @LocalServerPort
    int port;

    RestTemplate client = new RestTemplate();

    private String greetingUrl() {
        return "http://localhost:" + port + "/greeting";
    }

    @DisplayName("1. 인증 실패")
    @Test
    void test_1() {
        HttpClientErrorException exception = assertThrows(
                HttpClientErrorException.class,
                () -> client.getForObject(greetingUrl(), String.class)
        );
        assertEquals(401, exception.getRawStatusCode());
    }

    @DisplayName("2. 인증 성공")
    @Test
    void test_2() {
        // id : user1
        // pw : 1111 으로 로그인해서 헤더에 담겼다고 가정
        HttpHeaders headers = new HttpHeaders();
        String headerValue = String.format("Basic %s", Base64.getEncoder().encodeToString("user1:1111".getBytes()));
        headers.add(HttpHeaders.AUTHORIZATION, headerValue);

        HttpEntity<?> entity = new HttpEntity<>(null, headers);
        ResponseEntity<String> resp = client.exchange(greetingUrl(), HttpMethod.GET, entity, String.class);

        assertEquals("greeting!", resp.getBody());
    }

    @DisplayName("3. 2 인증 성공과 동일한 테스트")
    @Test
    void test_3() {
        // basic token 지원하는 테스트 템플릿
        TestRestTemplate testClient = new TestRestTemplate("user1", "1111");
        String response = testClient.getForObject(greetingUrl(), String.class);
        assertEquals("greeting!", response);
    }

    // POST method

    @DisplayName("4. POST 인증")
    @Test
    void test_4() {
        String name = "ben";
        TestRestTemplate testClient = new TestRestTemplate("user1", "1111");
        ResponseEntity<String> response = testClient.postForEntity(greetingUrl(), name, String.class);
        assertEquals(String.format("post : %s", name), response.getBody());
    }
}
