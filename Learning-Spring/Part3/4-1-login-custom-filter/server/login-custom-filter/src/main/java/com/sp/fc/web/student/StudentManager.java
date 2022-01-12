package com.sp.fc.web.student;

import java.util.HashMap;
import java.util.Set;

import org.springframework.beans.factory.InitializingBean;
import org.springframework.security.authentication.AuthenticationProvider;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.AuthenticationException;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.stereotype.Component;

@Component
public class StudentManager implements AuthenticationProvider, InitializingBean {

    // 원래는 db를 핸들링하여 가져와야하지만 테스트라서 간단하게 구현
    private HashMap<String, Student> studentDB = new HashMap<>();

    @Override
    public Authentication authenticate(Authentication authentication) throws AuthenticationException {
        StudentAuthenticationToken token = (StudentAuthenticationToken) authentication;

        if (studentDB.containsKey(token.getCredentials())) {
            Student student = studentDB.get(token.getCredentials());
            return StudentAuthenticationToken.builder()
                .principal(student)
                .details(student.getUsername())
                .authenticated(true)
                // .authorities(student.getRole())
                .build();
        }
        return null;
    }

    @Override
    public boolean supports(Class<?> authentication) {
        return authentication == StudentAuthenticationToken.class;
    }

    @Override
    public void afterPropertiesSet() throws Exception {
        Set.of(
            new Student("hong", "홍길동", Set.of(new SimpleGrantedAuthority("ROLE_STUDENT"))),
            new Student("puppy", "강아지", Set.of(new SimpleGrantedAuthority("ROLE_STUDENT"))),
            new Student("kitty", "고양이", Set.of(new SimpleGrantedAuthority("ROLE_STUDENT")))
        ).forEach(s ->
            studentDB.put(s.getId(), s)
        );
    }
}
