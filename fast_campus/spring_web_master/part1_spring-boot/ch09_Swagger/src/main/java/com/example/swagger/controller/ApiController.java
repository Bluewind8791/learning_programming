package com.example.swagger.controller;

import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import com.example.swagger.dto.UserReq;
import com.example.swagger.dto.UserRes;

import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiImplicitParams;
import io.swagger.annotations.ApiOperation;
import io.swagger.v3.oas.annotations.Operation;
import io.swagger.v3.oas.annotations.Parameter;
import io.swagger.v3.oas.annotations.parameters.RequestBody;
import io.swagger.v3.oas.annotations.responses.ApiResponse;
import io.swagger.v3.oas.annotations.responses.ApiResponses;


@RestController
@RequestMapping("/api")
public class ApiController {

    @Operation(summary = "summary", description = "description")
    @ApiResponses({
        @ApiResponse(responseCode = "200", description = "OK"),
        @ApiResponse(responseCode = "400", description = "Bad Request")
    })
    @GetMapping("/hello")
    public ResponseEntity<String> hello(
            @Parameter(description = "이름", required = true, example = "Ben") @RequestParam String name
        ) {
        return ResponseEntity.ok("hello" + name);
    }


    @ApiImplicitParams({
            @ApiImplicitParam(name = "x", value = "X value", required = true, dataType = "int", paramType = "path"),
            @ApiImplicitParam(name = "y", value = "Y value", required = true, dataType = "int", paramType = "query")
    })
    @GetMapping("/plus/{x}")
    public int plus(
        // @ApiParam(value = "X value")  //-> 대신 ApiImplicitParams 사용
        @RequestParam int x,
        // @ApiParam(value = "Y value")
        @RequestParam int y) {
        return x + y;
    }

    @ApiResponse(responseCode = "502", description = "사용자의 나이가 10살 이하일 때")
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
