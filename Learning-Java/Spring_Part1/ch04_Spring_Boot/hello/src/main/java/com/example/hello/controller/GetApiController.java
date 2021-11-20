package com.example.hello.controller;

import java.util.Map;

import com.example.hello.dto.UserRequest;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/api/get")
public class GetApiController {
  
  @GetMapping(path = "/hello")    // http://localhost:8080/api/get/hello
  public String hello() {
    return "GET Hello";
  }

  // old way 현재는 이렇게 잘 안씀
  // @RequestMapping("/hi")  -> 이렇게하면 get, post, put, delete 모든 메소드에 매핑됨
  @RequestMapping(path = "/hi", method = RequestMethod.GET) // 이렇게하면 get 메소드만 지정 get http://localhost:8080/api/get/hi
  public String hi() {
    return "GET Hi";
  }


  // http://localhost:8080/api/get/path-variable/{name}
  // name 을 받는다면?

  // @GetMapping("/path-variable/{name}")
  // public String pathVariable(@PathVariable String name) {
  //   System.out.println("Path Variable : " + name);
  //   return name;
  // }

  // 메서드 안의 변수 이름이 다르다면?
  @GetMapping("/path-variable/{id}")
  public String pathVariable(@PathVariable(name = "id") String pathName) {
    System.out.println("Path Variable : " + pathName);
    return pathName;
  }

  // Query Parameter 이란 uri 에서 ? 다음에 오며 key=value & key=value 이런식으로 붙는것
  // .../search? q = search
  // &oq = search
  // &aqs = edge..69i57j0i512l6j69i65l2.8703j0j1
  // &sourceid = chrome
  // &ie = UTF-8

  // http://localhost:8080/api/get/query-param?user=steve&email=steve@gmail.com&age=31
  @GetMapping(path = "query-param")
  public String queryParam(@RequestParam Map<String, String> queryParam) {
    
    StringBuilder sb = new StringBuilder();

    queryParam.entrySet().forEach(entry -> {
      System.out.println(entry.getKey());
      System.out.println(entry.getValue());
      System.out.println("\n");

      sb.append(entry.getKey() + " = " + entry.getValue() +"\n");
    });
    return sb.toString();
  }

  // 아무 변수나 다 받는것이 아닌 지정된 변수만 받기
  @GetMapping("query-param02")
  public String queryParam02(
    @RequestParam String name,
    @RequestParam String email,
    @RequestParam int age) {
    
    System.out.println(name);
    System.out.println(email);
    System.out.println(age);

    return name +" "+ email +" "+ age;
  }

  // ★ 가장 많이 쓰는 방법
  @GetMapping("query-param03")
  public String queryParam03(UserRequest userRequest) {
    System.out.println(userRequest.getName());
    System.out.println(userRequest.getEmail());
    System.out.println(userRequest.getAge());
    return userRequest.toString();
  }



} // end of class
