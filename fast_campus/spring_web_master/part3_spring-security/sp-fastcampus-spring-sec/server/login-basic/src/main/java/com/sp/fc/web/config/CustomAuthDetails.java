package com.sp.fc.web.config;

import java.time.LocalDateTime;

import javax.servlet.http.HttpServletRequest;

import org.springframework.security.authentication.AuthenticationDetailsSource;
import org.springframework.stereotype.Component;


/**
 * 인증객체 내의 details 추가
 */
@Component
public class CustomAuthDetails implements AuthenticationDetailsSource<HttpServletRequest, RequestInfo> {
    
    @Override
    public RequestInfo buildDetails(HttpServletRequest request) {
        return RequestInfo.builder()
            .remoteIp(request.getRemoteAddr())
            .sessionId(request.getSession().getId())
            .loginTime(LocalDateTime.now())
            .build()
        ;
    }
}
