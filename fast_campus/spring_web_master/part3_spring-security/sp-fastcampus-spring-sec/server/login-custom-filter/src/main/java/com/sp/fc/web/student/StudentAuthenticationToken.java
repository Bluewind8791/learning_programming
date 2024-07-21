package com.sp.fc.web.student;

import java.util.Collection;
import java.util.HashSet;

import lombok.*;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.GrantedAuthority;


/**
 * Student custom authentication token
 */
@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
public class StudentAuthenticationToken implements Authentication {

    private Student principal;
    private String credentials;
    private String details;
    private boolean authenticated; // 인증 도장

    @Override
    public String getName() {
        return principal == null ? "" : principal.getUsername();
    }

    // Student 객체가 GrantedAuthority를 가지고 있기때문에 principal이 null이라면 새로운 빈 객체를 생성하고, 있다면 getRole로 넘겨준다.
    @Override
    public Collection<? extends GrantedAuthority> getAuthorities() {
        return principal == null ? new HashSet<>() : principal.getRole();
    }
}
