package com.example.server.controller;

import java.net.URI;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.util.Base64;

import com.example.server.dto.Req;
import com.example.server.dto.User;

import org.springframework.http.RequestEntity;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestHeader;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.client.RestTemplate;
import org.springframework.web.util.UriComponentsBuilder;

import lombok.extern.slf4j.Slf4j;


@Slf4j
@RestController
@RequestMapping("/api/server")
public class ServerApiController {
    

    // https://openapi.naver.com/v1/search/local.json
    // ?query=%EC%A3%BC%EC%8B%9D
    // &display=10
    // &start=1
    // &sort=random
    @GetMapping("/naver")
    public String naver() {

        URI uri = UriComponentsBuilder
            .fromUriString("https://openapi.naver.com")
            .path("/v1/search/local.json")
            .queryParam("query", "중국집")
            .queryParam("display", 10)
            .queryParam("start", 1)
            .queryParam("sort", "random")
            .encode(Charset.forName("UTF-8"))
            .build()
            .toUri();
        
        log.info("uri : {}", uri);

        RestTemplate restTemplate = new RestTemplate();
        
        // header
        RequestEntity<Void> req = RequestEntity
            .get(uri)
            .header("X-Naver-Client-Id", "29ePxl3H1XTUdqOjcD4X")
            .header("X-Naver-Client-Secret", "qtu0G6tjle")
            .build();

        ResponseEntity<String> result = restTemplate.exchange(req, String.class);

        return result.getBody();
    }



    @GetMapping("/hello")
    public User hello(@RequestParam String name, @RequestParam int age) {
        User user = new User();
        user.setName(name);
        user.setAge(age);
        return user;
    }

    @PostMapping("/user/{userId}/name/{userName}")
    public Req<User> post(
                    // HttpEntity<String> entity,
                    @RequestBody Req<User> user,
                    @PathVariable int userId, 
                    @PathVariable String userName,
                    @RequestHeader("x-authorization") String authorization,
                    @RequestHeader("custom-header") String customHeader
                    ) {

        // log.info("req : {}", entity.getBody());
        log.info("User Id : {}, User Name : {}", userId, userName);
        log.info("Client request : {}", user);
        log.info("authorization : {}, custom : {}", authorization, customHeader);

        Req<User> response = new Req<>();
        response.setHeader(new Req.Header());
        response.setResBody(user.getResBody());

        return response;
    }
}
