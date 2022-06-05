package com.swagger.controller.dto;

import com.swagger.domain.User;

import lombok.Getter;

@Getter
public class UserResponseDto {

    private Long userId;
    private String email;
    private String nickname;

    public UserResponseDto(User entity) {
        this.userId = entity.getUserId();
        this.email = entity.getEmail();
        this.nickname = entity.getNickname();
    }

}
