package com.sp.fc.web.config;

import com.sp.fc.web.student.StudentManager;
import com.sp.fc.web.teacher.TeacherManager;

import org.springframework.boot.autoconfigure.security.servlet.PathRequest;
import org.springframework.security.config.annotation.authentication.builders.AuthenticationManagerBuilder;
import org.springframework.security.config.annotation.method.configuration.EnableGlobalMethodSecurity;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.builders.WebSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;
import org.springframework.security.web.authentication.UsernamePasswordAuthenticationFilter;

import lombok.RequiredArgsConstructor;

@RequiredArgsConstructor
@EnableWebSecurity(debug = true)
@EnableGlobalMethodSecurity(prePostEnabled = true) // Role
public class SecurityConfig extends WebSecurityConfigurerAdapter {

    private final StudentManager studentManager;
    private final TeacherManager teacherManager;

    @Override
    protected void configure(AuthenticationManagerBuilder auth) throws Exception {
        auth.authenticationProvider(studentManager);
        auth.authenticationProvider(teacherManager);
    }

    @Override
    protected void configure(HttpSecurity http) throws Exception {
        // http.formLogin 대신 custom login filter 사용
        CustomLoginFilter filter = new CustomLoginFilter(authenticationManager());

        http
                .authorizeRequests(request ->
                        request
                            .antMatchers("/", "/login").permitAll()
                            .anyRequest().authenticated()
                )
                // custom filter가 정의한 부분이 적기때문에 해당 form login에서 해당 부분을 빌려와서 사용
                .formLogin(login ->
                        login
                            .loginPage("/login").permitAll()
                            .defaultSuccessUrl("/", false)
                            .failureUrl("/login-error")
                )

                // UsernamePasswordAuthenticationFilter 자리에 해당 필터 적용
                .addFilterAt(filter, UsernamePasswordAuthenticationFilter.class)
                .logout(logout -> logout.logoutSuccessUrl("/"))
                .exceptionHandling(e -> e.accessDeniedPage("/access-denied"))
        ;
    }

    @Override
    public void configure(WebSecurity web) throws Exception {
        web.ignoring()
            .requestMatchers(PathRequest.toStaticResources().atCommonLocations())
            ;
    }
}
