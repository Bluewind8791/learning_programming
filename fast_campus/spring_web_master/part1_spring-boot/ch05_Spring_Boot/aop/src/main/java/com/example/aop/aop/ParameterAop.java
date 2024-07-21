package com.example.aop.aop;

import java.lang.reflect.Method;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.AfterReturning;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.aspectj.lang.annotation.Pointcut;
import org.aspectj.lang.reflect.MethodSignature;
import org.springframework.stereotype.Component;

@Aspect // aop 동작
@Component // spring에서 관리
public class ParameterAop {
    
    @Pointcut("execution(* com.example.aop.controller..*.*(..))")
    private void cut() {}


    @Before("cut()") // cut method 전에 실행하고
    public void before(JoinPoint joinPoint) {

        //method 이름 출력
        MethodSignature methodSignature = (MethodSignature) joinPoint.getSignature();
        Method method = methodSignature.getMethod();
        System.out.println(method.getName());

        Object[] args = joinPoint.getArgs();

        for(Object obj : args) {
            System.out.println("type : " + obj.getClass().getSimpleName());
            System.out.println("value : " + obj);
        }
    }


    // cut method가 정상실행되면 returnObj 실행
    @AfterReturning(value = "cut()", returning = "returnObj")
    public void afterReturn(JoinPoint joinPoint, Object returnObj) {
        System.out.println("return obj");
        System.out.println(returnObj);
    }
}
