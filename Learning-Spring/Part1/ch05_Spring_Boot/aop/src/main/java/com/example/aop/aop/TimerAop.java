package com.example.aop.aop;

import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Pointcut;
import org.springframework.stereotype.Component;
import org.springframework.util.StopWatch;

// bean은 클래스에 붙일수없고 component를 붙여서 class 단위로 bean에 붙임
// bean은 method에 붙일수있다.

@Aspect
@Component
public class TimerAop {
    
    @Pointcut("execution(* com.example.aop.controller..*.*(..))")
    private void cut() {}


    @Pointcut("@annotation(com.example.aop.annotation.Timer)")
    private void enableTimer() {}


    // before after 하면 타임을 공유할수없음
    @Around("cut() && enableTimer()")
    public void around(ProceedingJoinPoint joinPoint) throws Throwable {

        StopWatch stopWatch = new StopWatch();
        stopWatch.start();


        Object result = joinPoint.proceed();

        stopWatch.stop();

        System.out.println("total time : " + stopWatch.getTotalTimeSeconds());
    }
}
