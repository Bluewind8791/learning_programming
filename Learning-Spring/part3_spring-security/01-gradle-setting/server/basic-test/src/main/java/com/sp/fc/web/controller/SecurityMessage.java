package com.sp.fc.web.controller;

import lombok.Data;
import lombok.Builder;
import lombok.NoArgsConstructor;

import org.springframework.security.core.Authentication;

import lombok.AllArgsConstructor;


@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
public class SecurityMessage {

    private Authentication auth;
    private String message;
}
