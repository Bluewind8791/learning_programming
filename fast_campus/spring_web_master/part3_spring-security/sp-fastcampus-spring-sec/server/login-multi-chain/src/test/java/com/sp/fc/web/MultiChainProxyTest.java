package com.sp.fc.web;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

import java.util.List;

import com.sp.fc.web.student.Student;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.context.SpringBootTest.WebEnvironment;
import org.springframework.boot.test.web.client.TestRestTemplate;
import org.springframework.boot.web.server.LocalServerPort;
import org.springframework.core.ParameterizedTypeReference;
import org.springframework.http.HttpMethod;
import org.springframework.http.ResponseEntity;

@SpringBootTest(webEnvironment = WebEnvironment.RANDOM_PORT)
public class MultiChainProxyTest {

    @LocalServerPort
    int port;

    TestRestTemplate testclient = new TestRestTemplate("choi", "1");

    @DisplayName("1. choi:1 로 로그인하여 학생 리스트를 내려받는다.")
    @Test
    void test_1() {
        
        ResponseEntity<List<Student>> response = testclient.exchange(
                "http://localhost:" + port + "/api/teacher/students",
                HttpMethod.GET,
                null,
                new ParameterizedTypeReference<List<Student>>() {}
        );
        System.out.println("response = " + response.getBody());
        assertNotNull(response.getBody());
        assertEquals(3, response.getBody().size());
    }

}
