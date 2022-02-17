package com.sp.fc.web.config;

import java.util.Optional;
import java.util.Set;

import com.sp.fc.user.domain.Authority;
import com.sp.fc.user.domain.School;
import com.sp.fc.user.domain.User;
import com.sp.fc.user.service.SchoolService;
import com.sp.fc.user.service.UserService;

import org.springframework.boot.CommandLineRunner;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Component;

import lombok.RequiredArgsConstructor;

// for test init DB
@Component
@RequiredArgsConstructor
public class DBInit implements CommandLineRunner { // CommandLineRunner 시스템 시작시 실행

    private final UserService userService;
    private final SchoolService schoolService;
    private final PasswordEncoder passwordEncoder;

    @Override
    public void run(String... args) throws Exception {
        School defaultSchool = schoolService.findSchool(1L).orElseGet(() -> 
            schoolService.save(School.builder()
                                    .name("test school")
                                    .city("Seoul")
                                    .build()
            )
        );

        userService.findByEmail("admin@test.com").or(() -> {
            User admin = User.builder()
                            .name("admin")
                            .email("admin@test.com")
                            .password(passwordEncoder.encode("1234"))
                            .enabled(true)
                            .school(defaultSchool)
                            .build();
            admin = userService.save(admin);
            admin.setAuthorities(Set.of(
                new Authority(admin.getUserId(), Authority.ROLE_ADMIN),
                new Authority(admin.getUserId(), Authority.ROLE_TEACHER),
                new Authority(admin.getUserId(), Authority.ROLE_STUDENT)
            ));
            return Optional.of(userService.save(admin));
        });

        userService.findByEmail("teacher@test.com").or(()->{
            User teacher = User.builder()
                    .name("teacher")
                    .email("teacher@test.com")
                    .password(passwordEncoder.encode("1234"))
                    .enabled(true)
                    .school(defaultSchool)
                    .build();
            teacher = userService.save(teacher);
            teacher.setAuthorities(Set.of(
                    new Authority(teacher.getUserId(), Authority.ROLE_TEACHER)
            ));
            return Optional.of(userService.save(teacher));
        });

        userService.findByEmail("study@test.com").or(()->{
            User study = User.builder()
                    .name("study")
                    .email("study@test.com")
                    .password(passwordEncoder.encode("1234"))
                    .enabled(true)
                    .school(defaultSchool)
                    .build();
            study = userService.save(study);
            study.setAuthorities(Set.of(
                    new Authority(study.getUserId(), Authority.ROLE_STUDENT)
            ));
            return Optional.of(userService.save(study));
        });
    }


}