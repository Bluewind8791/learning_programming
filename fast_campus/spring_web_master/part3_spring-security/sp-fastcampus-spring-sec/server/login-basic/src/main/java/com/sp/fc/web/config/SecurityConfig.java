package com.sp.fc.web.config;

import lombok.RequiredArgsConstructor;
import org.springframework.boot.autoconfigure.security.servlet.PathRequest;
import org.springframework.context.annotation.Bean;
import org.springframework.security.access.hierarchicalroles.RoleHierarchy;
import org.springframework.security.access.hierarchicalroles.RoleHierarchyImpl;
import org.springframework.security.config.annotation.authentication.builders.AuthenticationManagerBuilder;
import org.springframework.security.config.annotation.method.configuration.EnableGlobalMethodSecurity;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.builders.WebSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;
import org.springframework.security.core.userdetails.User;


@RequiredArgsConstructor
@EnableWebSecurity(debug = true)
@EnableGlobalMethodSecurity(prePostEnabled = true) // role 적용
public class SecurityConfig extends WebSecurityConfigurerAdapter {

    private final CustomAuthDetails customAuthDetails;

    /**
     * only for test
     * @param auth the {@link AuthenticationManagerBuilder} to use
     * @throws Exception
     */
    @Override
    protected void configure(AuthenticationManagerBuilder auth) throws Exception {
    auth
        .inMemoryAuthentication()
        .withUser(
            User.withDefaultPasswordEncoder()
                .username("user1")
                .password("1111")
                .roles("USER")
        )
        .withUser(
            User.withDefaultPasswordEncoder()
                .username("admin")
                .password("2222")
                .roles("ADMIN")
        );
    }

    /**
     * ROLE 계층 설정
     * @return
     */
    @Bean
    RoleHierarchy roleHierarchy() {
        // ROLE_ADMIN의 권한은 ROLE_USER의 권한을 포함한다
        RoleHierarchyImpl roleHierarchy = new RoleHierarchyImpl();
        roleHierarchy.setHierarchy("ROLE_ADMIN > ROLE_USER");
        return roleHierarchy;
    }

    @Override
    protected void configure(HttpSecurity http) throws Exception {
        http
            .authorizeRequests()
                .antMatchers("/").permitAll()
                .anyRequest().authenticated()
                .and()
            .formLogin()
                .loginPage("/login").permitAll() // 무한루프 방지
                .defaultSuccessUrl("/", false)
                .failureUrl("/login-error")
                .authenticationDetailsSource(customAuthDetails)
                .and()
            .logout()
                .logoutSuccessUrl("/")
                .and()
            .exceptionHandling()
                .accessDeniedPage("/access-denied")
        ;
    }

    @Override
    public void configure(WebSecurity web) throws Exception {
        // resources/static의 하위 디렉토리를 web resource로 설정하여 시큐리티 ignore
        web.ignoring()
                .requestMatchers(
                        PathRequest.toStaticResources().atCommonLocations()
                );
    }
}
