package com.swagger.config;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.http.HttpHeaders;

import io.swagger.v3.oas.models.Components;
import io.swagger.v3.oas.models.OpenAPI;
import io.swagger.v3.oas.models.info.Contact;
import io.swagger.v3.oas.models.info.Info;
import io.swagger.v3.oas.models.security.SecurityRequirement;
import io.swagger.v3.oas.models.security.SecurityScheme;

@Configuration
public class SpringDocConfig {

    @Bean
    public OpenAPI openAPI() {
        Info info = new Info()
            .title("title")
            .version("1.0")
            .description("description")
            .contact(new Contact().email("test@kakao.com").name("Bluewind Kim"));

        // Security Schemes Item
        SecurityScheme securityScheme = new SecurityScheme()
            .type(SecurityScheme.Type.HTTP)
            .scheme("bearer")
            .bearerFormat("JWT")
            .in(SecurityScheme.In.HEADER)
            .name(HttpHeaders.AUTHORIZATION);

        SecurityRequirement securityItem = new SecurityRequirement();
        securityItem.addList("JWT");

        return new OpenAPI()
            .components(new Components().addSecuritySchemes("key", securityScheme)) // Security 인증 컴포넌트 설정
            .addSecurityItem(securityItem)
            .info(info);
    }
/*
API 문서의 정보를 설정하고 JWT를 통한 인증을 해야 하므로 Security 설정을 추가해주었다.
위처럼 설정하면 실제 API를 요청하는 것 처럼 토큰으로 인증 후 API를 호출할 수 있다.
*/
}