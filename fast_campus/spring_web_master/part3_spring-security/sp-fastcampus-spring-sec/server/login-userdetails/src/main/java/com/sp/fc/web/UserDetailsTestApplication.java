package com.sp.fc.web;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.autoconfigure.domain.EntityScan;
import org.springframework.data.jpa.repository.config.EnableJpaRepositories;


// UserAdminModule에서 해당 스캔 config 정보를 설정
//@EntityScan(basePackages = {
//    "com.sp.fc.user.domain",
//})
//@EnableJpaRepositories(basePackages = {
//    "com.sp.fc.user.repository",
//})
@SpringBootApplication(scanBasePackages = {
//    "com.sp.fc.user",
    "com.sp.fc.config",
    "com.sp.fc.web",
})
public class UserDetailsTestApplication {
    public static void main(String[] args) {
        SpringApplication.run(UserDetailsTestApplication.class, args);
    }
}
