package com.sp.fc.config;

import org.springframework.boot.autoconfigure.domain.EntityScan;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.data.jpa.repository.config.EnableJpaRepositories;

@Configuration
@ComponentScan("com.sp.fc.user") // scan
@EnableJpaRepositories(basePackages = {
        "com.sp.fc.user.repository" // repository 지정
})
@EntityScan(basePackages = { // entity scan
        "com.sp.fc.user.domain"
})
public class PaperUserModule {

        // config 는 user module 실제 어플리케이션에서 bean과 특징들을 스캔하기 위한 정보들을 취합한다.
}
