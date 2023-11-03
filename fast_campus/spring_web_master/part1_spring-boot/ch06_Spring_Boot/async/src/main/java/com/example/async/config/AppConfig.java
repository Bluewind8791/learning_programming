package com.example.async.config;

import java.util.concurrent.Executor;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.scheduling.concurrent.ThreadPoolTaskExecutor;



@Configuration
public class AppConfig {
    
    @Bean("async-thread")
    public Executor asyncThread() {
        ThreadPoolTaskExecutor threadPoolTaskExecutor = new ThreadPoolTaskExecutor();
        threadPoolTaskExecutor.setMaxPoolSize(100); // 쓰레드 풀의 최대 사이즈
        threadPoolTaskExecutor.setCorePoolSize(10); // 동시에 실행시킬 쓰레드의 개수 / 코어풀이 차면 queue에 들어가고 큐도 차면 코어풀이 20으로 늘어남
        threadPoolTaskExecutor.setQueueCapacity(10); // 쓰레드 풀 큐의 사이즈, 
        threadPoolTaskExecutor.setThreadNamePrefix("Async-");
        return threadPoolTaskExecutor;
    }
}
