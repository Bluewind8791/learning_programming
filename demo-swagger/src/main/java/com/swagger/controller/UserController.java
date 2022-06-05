package com.swagger.controller;

import org.springframework.hateoas.EntityModel;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.servlet.ModelAndView;

import com.swagger.config.SpringDocApiResponse;
import com.swagger.controller.dto.UserRequestDto;
import com.swagger.domain.Role;
import com.swagger.domain.User;
import com.swagger.repository.UserRepository;

import io.swagger.v3.oas.annotations.Operation;
import io.swagger.v3.oas.annotations.tags.Tag;
import lombok.RequiredArgsConstructor;

import static org.springframework.hateoas.server.mvc.WebMvcLinkBuilder.*;

import java.util.HashMap;
import java.util.Map;

@RestController
@RequiredArgsConstructor
@Tag(name = "User Controller", description = "유저를 CRUD 하는 API 컨트롤러입니다.")
public class UserController {

    private final UserRepository userRepository;

    // save user
    @PostMapping("/users")
    @SpringDocApiResponse
    @Operation(summary = "회원가입", description = "회원 테이블을 생성합니다.")
    public ResponseEntity<?> save(@RequestBody UserRequestDto dto) {
        User user = User.builder()
            .email(dto.getEmail())
            .nickname(dto.getNickname())
            .role(Role.USER)
            .build();
        userRepository.save(user);
        return ResponseEntity.ok(
            EntityModel.of(user).add(linkTo(methodOn(UserController.class).save(dto)).withSelfRel())
        );
    }

    // 모든 유저 리스트
    @GetMapping("/users")
    @SpringDocApiResponse
    @Operation(summary = "유저 리스트 페이지", description = "모든 유저를 확인합니다.")
    public ModelAndView home() {
        Map<String, Object> model = new HashMap<>();
        model.put("users", userRepository.findAll());
        return new ModelAndView("users", HttpStatus.OK);
    }

}
