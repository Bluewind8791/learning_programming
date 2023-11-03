package com.sp.fc.web.student;

import java.util.HashMap;
import java.util.Set;

import org.springframework.beans.factory.InitializingBean;
import org.springframework.security.authentication.AuthenticationProvider;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.AuthenticationException;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.stereotype.Component;


/**
 * Student Authentication Provider
 */
@Component
public class StudentManager implements AuthenticationProvider, InitializingBean {

    // 원래는 db를 핸들링하여 가져와야하지만 테스트라서 간단하게 구현
    private final HashMap<String, Student> studentDB = new HashMap<>();

    @Override
    public Authentication authenticate(Authentication authentication) throws AuthenticationException {
//        UsernamePasswordAuthenticationToken token = (UsernamePasswordAuthenticationToken) authentication;
//        if (studentDB.containsKey(token.getName())) {
//            Student student = studentDB.get(token.getName());
//            return StudentAuthenticationToken.builder()
//                    .principal(student)
//                    .authenticated(true)
//                    .details(student.getUsername()) // no use
//                    .build();
//        }

        // After customize Token
        StudentAuthenticationToken token = (StudentAuthenticationToken) authentication;
        if (studentDB.containsKey(token.getCredentials())) {
            Student student = studentDB.get(token.getCredentials());
            return StudentAuthenticationToken.builder()
                .principal(student)
                .details(student.getUsername())
                .authenticated(true)
                .build();
        }

        // 해당 토큰을 처리할 수 없는 경우 null로 넘거야 한다.
        return null;
    }

    @Override
    public boolean supports(Class<?> authentication) {
//        return authentication == UsernamePasswordAuthenticationToken.class;
        return authentication == StudentAuthenticationToken.class;
    }

    /**
     * Bean이 초기화 된 후 값 세팅
     * for test
     * @throws Exception
     */
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
