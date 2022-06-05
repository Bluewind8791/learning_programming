package com.swagger.controller.dto;

import javax.validation.constraints.NotEmpty;

import io.swagger.v3.oas.annotations.media.Schema;
import lombok.Builder;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@NoArgsConstructor
public class UserRequestDto {

    @NotEmpty
    @Schema(description = "회원의 이메일", required = true, example = "example@email.com")
    private String email;

    @NotEmpty
    @Schema(description = "회원의 닉네임", required = true, example = "홍길동")
    private String nickname;

    @Builder
    public UserRequestDto(String nickname, String email) {
        this.email = email;
        this.nickname = nickname;
    }

}