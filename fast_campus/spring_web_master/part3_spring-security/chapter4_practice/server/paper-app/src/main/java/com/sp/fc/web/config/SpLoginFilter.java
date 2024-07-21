package com.sp.fc.web.config;

import java.io.IOException;

import javax.servlet.FilterChain;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.security.authentication.AuthenticationManager;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.AuthenticationException;
import org.springframework.security.web.authentication.RememberMeServices;
import org.springframework.security.web.authentication.UsernamePasswordAuthenticationFilter;
import org.springframework.security.web.util.matcher.AntPathRequestMatcher;

import lombok.SneakyThrows;


public class SpLoginFilter extends UsernamePasswordAuthenticationFilter {
    
    private final AuthenticationManager authenticationManager;
    
    public SpLoginFilter(
        AuthenticationManager authenticationManager,
        RememberMeServices rememberMeServices
    ) {
        this.authenticationManager = authenticationManager;
        this.setRequiresAuthenticationRequestMatcher(new AntPathRequestMatcher("/login", "POST")); // pattern, httpMethod
        this.setAuthenticationSuccessHandler(new LoginSuccessHandler());
        this.setAuthenticationFailureHandler(new LoginFailureHandler());
        this.setRememberMeServices(rememberMeServices);
    }

    @Override
    @SneakyThrows // @SneakyThrows 어노테이션을 사용한 메소드에서 예외가 발생하면 catch문에서 e.printStackTrace(); 메소드를 호출한 것과 같이 예외가 출력된다. 
    public Authentication attemptAuthentication(HttpServletRequest request, HttpServletResponse response)
            throws AuthenticationException {
        UserLogin userLogin = UserLogin.builder()
                                        .username(request.getParameter("username"))
                                        .password(request.getParameter("password"))
                                        .site(request.getParameter("site"))
                                        .rememberme(request.getParameter("rememeber=me") != null)
                                        .build();
        UsernamePasswordAuthenticationToken authToken = new UsernamePasswordAuthenticationToken(
            userLogin.getUsername(), userLogin.getPassword(), null
        );
        return authenticationManager.authenticate(authToken);
    }

    @Override
    protected void successfulAuthentication(
            HttpServletRequest request,
            HttpServletResponse response,
            FilterChain chain,
            Authentication authResult) throws IOException, ServletException
    {
        super.successfulAuthentication(request, response, chain, authResult);
    }

    @Override
    protected void unsuccessfulAuthentication(
            HttpServletRequest request,
            HttpServletResponse response,
            AuthenticationException failed) throws IOException, ServletException {
        super.unsuccessfulAuthentication(request, response, failed);
    }

    public static String getIp(HttpServletRequest request) {
        String ip = request.getHeader("X-Forwarded-For");
        if (ip == null || ip.length() == 0 || "unknown".equalsIgnoreCase(ip)) {
            ip = request.getHeader("Proxy-Client-IP");
        }
        if (ip == null || ip.length() == 0 || "unknown".equalsIgnoreCase(ip)) {
            ip = request.getHeader("WL-Proxy-Client-IP");
        }
        if (ip == null || ip.length() == 0 || "unknown".equalsIgnoreCase(ip)) {
            ip = request.getHeader("HTTP_CLIENT_IP");
        }
        if (ip == null || ip.length() == 0 || "unknown".equalsIgnoreCase(ip)) {
            ip = request.getHeader("HTTP_X_FORWARDED_FOR");
        }
        if (ip == null || ip.length() == 0 || "unknown".equalsIgnoreCase(ip)) {
            ip = request.getRemoteAddr();
        }
        return ip;
    }





}
