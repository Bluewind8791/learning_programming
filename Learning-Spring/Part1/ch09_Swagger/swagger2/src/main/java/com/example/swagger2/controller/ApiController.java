package com.example.swagger2.controller;

import com.example.swagger2.dto.UserReq;
import com.example.swagger2.dto.UserRes;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiImplicitParams;
import io.swagger.annotations.ApiOperation;
// import io.swagger.annotations.ApiParam;
import io.swagger.annotations.ApiResponse;
import io.swagger.v3.oas.annotations.parameters.RequestBody;

@Api(tags = {"This is providing API information Controller"})
@RestController
@RequestMapping("/api")
public class ApiController {
    
    @GetMapping("/hello")
    public String hello() {
        return "hello";
    }

    @ApiImplicitParams({
            @ApiImplicitParam(name = "x", value = "X value", required = true, dataType = "int", paramType = "path"),
            @ApiImplicitParam(name = "y", value = "Y value", required = true, dataType = "int", paramType = "query")
    })
    @GetMapping("/plus/{x}")
    public int plus(
        // @ApiParam(value = "x value")  -> 대신 ApiImplicitParams 사용
        @RequestParam int x,
        // @ApiParam(value = "y value")
        @RequestParam int y) {
        return x + y;
    }

    @ApiResponse(code = 502, message = "사용자의 나이가 10살 이하일 때")
    @ApiOperation(value = "사용자의 이름과 나이를 return하는 Method")
    @GetMapping("/user")
    public UserRes user(UserReq userReq) {
        return new UserRes(userReq.getName(), userReq.getAge());
    }

    @PostMapping("/user")
    public UserRes userPost(@RequestBody UserReq req) {
        return new UserRes(req.getName(), req.getAge());
    }
}
