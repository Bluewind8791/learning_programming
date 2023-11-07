package com.sp.fc.web.config;

import lombok.RequiredArgsConstructor;
import org.springframework.security.access.AccessDecisionManager;
import org.springframework.security.access.AccessDeniedException;
import org.springframework.security.access.ConfigAttribute;
import org.springframework.security.authentication.InsufficientAuthenticationException;
import org.springframework.security.config.annotation.authentication.builders.AuthenticationManagerBuilder;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.web.FilterInvocation;
import org.springframework.security.web.access.intercept.FilterSecurityInterceptor;

import java.util.Collection;

@EnableWebSecurity
@RequiredArgsConstructor
public class SecurityConfig extends WebSecurityConfigurerAdapter {

    @Override
    protected void configure(HttpSecurity http) throws Exception {
        http
                .csrf().disable()
                .httpBasic()
                    .and()
                .authorizeRequests()
                    .mvcMatchers("/greeting/{name}").hasRole("USER")
                    .anyRequest().authenticated()
//                    .accessDecisionManager(filterAccessDecisionManager()) // .mvcMatchers("/greeting/{name}").hasRole("ADMIN") 뚫기
//                    .access("@nameCheck.check(#name)")
        ;
    }

    // 접근 권한 커스텀
    private AccessDecisionManager filterAccessDecisionManager() {
        return new AccessDecisionManager() {
            @Override
            public void decide(Authentication authentication, Object object, Collection<ConfigAttribute> configAttributes) throws AccessDeniedException, InsufficientAuthenticationException {
//                throw new AccessDeniedException("접근 금지");
                return; // pass 처리
            }

            @Override
            public boolean supports(ConfigAttribute attribute) {
                return true;
            }

            @Override
            public boolean supports(Class<?> clazz) {
                return FilterInvocation.class.isAssignableFrom(clazz);
            }
        };
    }

    /**
     * Just for testing
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
                        .roles("USER", "STUDENT")
                )
                .withUser(
                        User.withDefaultPasswordEncoder()
                                .username("user2")
                                .password("1111")
                                .roles("USER", "STUDENT")
                )
                .withUser(
                        User.withDefaultPasswordEncoder()
                                .username("tutor1")
                                .password("1111")
                                .roles("USER", "TUTOR")
                )
                .withUser(
                        User.withDefaultPasswordEncoder()
                                .username("primary")
                                .password("1111")
                                .roles("USER", "PRIMARY")
                )
        ;
    }
}
