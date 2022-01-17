package com.example.aop.aop;

import java.io.UnsupportedEncodingException;
import java.util.Base64;

import com.example.aop.dto.User;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.AfterReturning;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.aspectj.lang.annotation.Pointcut;
import org.springframework.stereotype.Component;

@Aspect
@Component
public class DecodeAop {
    
    @Pointcut("execution(* com.example.aop.controller..*.*(..))")
    private void cut() {}


    @Pointcut("@annotation(com.example.aop.annotation.Timer)")
    private void enableDecode() {}


    // before decode
    @Before("cut() && enableDecode()")
    public void before(JoinPoint joinPoint) throws UnsupportedEncodingException {
        
        Object[] args = joinPoint.getArgs();

        for (Object arg : args) { // argument 돌다가

            if (arg instanceof User) { // argument 중에 user랑 매칭되는것이 있으면
                User user = User.class.cast(arg); // User 형변환
                String base64Email = user.getEmail(); // email를 꺼냄
                String email = new String(Base64.getDecoder().decode(base64Email), "UTF-8"); // decode시킴
                user.setEmail(email);
            }
        }
    }


    // after encode
    @AfterReturning(value = "cut() && enableDecode()", returning = "returnObj")
    public void afterReturn(JoinPoint joinPoint, Object returnObj) {
        if (returnObj instanceof User) {

            User user = User.class.cast(returnObj); // User 형변환
            String email = user.getEmail(); // email를 꺼냄
            String base64Email = Base64.getEncoder().encodeToString(email.getBytes()); // eecode시킴
            user.setEmail(base64Email);
        }
    }
    
}
