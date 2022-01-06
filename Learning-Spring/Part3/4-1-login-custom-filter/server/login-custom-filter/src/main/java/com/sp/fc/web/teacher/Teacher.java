package com.sp.fc.web.teacher;

import lombok.Data;
import lombok.Builder;
import lombok.NoArgsConstructor;

import java.util.Set;

import org.springframework.security.core.GrantedAuthority;

import lombok.AllArgsConstructor;


@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
public class Teacher {
    
    private String id;
    private String username;
    private Set<GrantedAuthority> role;
}
