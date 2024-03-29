package com.sp.fc.web.teacher;

import java.util.HashMap;
import java.util.Set;

import org.springframework.beans.factory.InitializingBean;
import org.springframework.security.authentication.AuthenticationProvider;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.AuthenticationException;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.stereotype.Component;

@Component
public class TeacherManager implements AuthenticationProvider, InitializingBean {

    private HashMap<String, Teacher> teacherDB = new HashMap<>();

    @Override
    public Authentication authenticate(Authentication authentication) throws AuthenticationException {
//        UsernamePasswordAuthenticationToken token = (UsernamePasswordAuthenticationToken) authentication;
//        if (teacherDB.containsKey(token.getName())) {
//            Teacher teacher = teacherDB.get(token.getName());
//            return TeacherAuthenticationToken.builder()
//                    .principal(teacher)
//                    .authenticated(true)
//                    .details(teacher.getUsername()) // no use
//                    .build();
//        }

        TeacherAuthenticationToken token = (TeacherAuthenticationToken) authentication;

        if (teacherDB.containsKey(token.getCredentials())) {
            Teacher teacher = teacherDB.get(token.getCredentials());
            return TeacherAuthenticationToken.builder()
                    .principal(teacher)
                    .details(teacher.getUsername())
                    .authenticated(true)
                    .build();
        }
        return null;
    }

    @Override
    public boolean supports(Class<?> authentication) {
//        return authentication == UsernamePasswordAuthenticationToken.class;
        return authentication == TeacherAuthenticationToken.class;
    }

    @Override
    public void afterPropertiesSet() throws Exception {
        Set.of(
            new Teacher("lee", "이성계", Set.of(new SimpleGrantedAuthority("ROLE_TEACHER"))),
            new Teacher("orang", "오랑우탄", Set.of(new SimpleGrantedAuthority("ROLE_TEACHER"))),
            new Teacher("chim", "침팬지", Set.of(new SimpleGrantedAuthority("ROLE_TEACHER")))
        ).forEach(s ->
            teacherDB.put(s.getId(), s)
        );
    }

}
