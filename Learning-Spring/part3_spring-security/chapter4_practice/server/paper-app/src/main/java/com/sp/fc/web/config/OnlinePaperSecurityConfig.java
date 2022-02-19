package com.sp.fc.web.config;

import com.sp.fc.user.service.UserSecurityService;

import org.springframework.boot.autoconfigure.security.servlet.PathRequest;
import org.springframework.context.annotation.Bean;
import org.springframework.security.config.annotation.authentication.builders.AuthenticationManagerBuilder;
import org.springframework.security.config.annotation.method.configuration.EnableGlobalMethodSecurity;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.builders.WebSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.security.web.authentication.RememberMeServices;
import org.springframework.security.web.authentication.UsernamePasswordAuthenticationFilter;
import org.springframework.security.web.authentication.rememberme.TokenBasedRememberMeServices;

import lombok.RequiredArgsConstructor;

@EnableWebSecurity
@RequiredArgsConstructor
@EnableGlobalMethodSecurity(prePostEnabled = true)
public class OnlinePaperSecurityConfig extends WebSecurityConfigurerAdapter {

    private final UserSecurityService userSecurityService;

    @Bean
    PasswordEncoder passwordEncoder() {
        return new BCryptPasswordEncoder();
    }

    @Override
    protected void configure(AuthenticationManagerBuilder auth) throws Exception {
        auth
            .userDetailsService(userSecurityService)
            .passwordEncoder(passwordEncoder())
        ;
    }

    @Override
    protected void configure(HttpSecurity http) throws Exception {

        final SpLoginFilter filter = new SpLoginFilter(authenticationManagerBean(), rememberMeServices());

        http
            .csrf().disable()
            .formLogin(login -> {
                login.loginPage("/login");
            })
            .logout(logout -> {
                logout.logoutSuccessUrl("/");
            })
            .rememberMe(config -> {
                config.rememberMeServices(rememberMeServices());
            })
            .addFilterAt(filter, UsernamePasswordAuthenticationFilter.class)
            .exceptionHandling(exception -> { 
                exception.accessDeniedPage("/access-denied"); // exception 발생시 이 페이지로 이동
            })
            .authorizeRequests(request -> 
                request
                        .antMatchers("/").permitAll()
                        .antMatchers("/login").permitAll()
                        .antMatchers("/error").permitAll()
                        .antMatchers("/signup/*").permitAll()
                        .antMatchers("/study/**").hasAnyAuthority("ROLE_ADMIN", "ROLE_STUDENT") // admin이나 student 모두 접근 가능
                        .antMatchers("/teacher/**").hasAnyAuthority("ROLE_ADMIN", "ROLE_TEACHER")
                        .antMatchers("/manager/**").hasAnyAuthority("ROLE_ADMIN")
            );
    }

    @Override
    public void configure(WebSecurity web) throws Exception {
        web.ignoring()
                    .requestMatchers(PathRequest.toStaticResources().atCommonLocations());
    }


    private RememberMeServices rememberMeServices() {
        TokenBasedRememberMeServices rememberMeServices = new TokenBasedRememberMeServices(
            "paper-site-remember-me", // key
            userSecurityService // user details service
        );
        rememberMeServices.setParameter("remember-me");
        rememberMeServices.setAlwaysRemember(true);
        rememberMeServices.setTokenValiditySeconds(60*60); // token 유효기간 1시간
        return rememberMeServices;
    }


}
