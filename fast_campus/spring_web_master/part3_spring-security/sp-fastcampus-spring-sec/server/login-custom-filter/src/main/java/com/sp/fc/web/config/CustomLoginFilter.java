package com.sp.fc.web.config;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.sp.fc.web.student.Student;
import com.sp.fc.web.student.StudentAuthenticationToken;
import com.sp.fc.web.teacher.Teacher;
import com.sp.fc.web.teacher.TeacherAuthenticationToken;

import org.springframework.security.authentication.AuthenticationManager;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.AuthenticationException;
import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.security.web.authentication.UsernamePasswordAuthenticationFilter;

import java.util.Set;

public class CustomLoginFilter extends UsernamePasswordAuthenticationFilter {

    public CustomLoginFilter(AuthenticationManager authenticationManager) {
        super(authenticationManager);
    }

    /**
     * 인증 시도 (Token 발행)
     * @param request from which to extract parameters and perform the authentication
     * @param response the response, which may be needed if the implementation has to do a
     * redirect as part of a multi-stage authentication process (such as OpenID).
     * @return
     * @throws AuthenticationException
     */
    @Override
    public Authentication attemptAuthentication(HttpServletRequest request, HttpServletResponse response) throws AuthenticationException {

        String username = obtainUsername(request);
        username = (username != null) ? username : "";
        username = username.trim();
        String password = obtainPassword(request);
        password = (password != null) ? password : "";

//        UsernamePasswordAuthenticationToken token = new UsernamePasswordAuthenticationToken(username, password);
//        return this.getAuthenticationManager().authenticate(token);

        // 타입에 따라서 토큰을 다르게 발행
        String type = request.getParameter("type");
        if ("student".equals(type)) {
            // student
            StudentAuthenticationToken token = StudentAuthenticationToken.builder()
                    // 실제 상황에서는 이렇게 쓰면 안된다...
                    .principal(new Student("id", username, Set.of(new SimpleGrantedAuthority("ROLE_STUDENT"))))
                    .credentials(password)
                    .build();

            return this.getAuthenticationManager().authenticate(token);
        } else {
            // teacher
            TeacherAuthenticationToken token = TeacherAuthenticationToken.builder()
                    .principal(new Teacher("id", username, Set.of(new SimpleGrantedAuthority("ROLE_TEACHER"))))
                    .credentials(password)
                    .build();

            return this.getAuthenticationManager().authenticate(token);
        }
    }
}
