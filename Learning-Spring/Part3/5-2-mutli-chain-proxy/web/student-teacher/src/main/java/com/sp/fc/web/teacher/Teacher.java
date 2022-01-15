package com.sp.fc.web.teacher;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.security.core.GrantedAuthority;

import java.util.Set;

import com.fasterxml.jackson.annotation.JsonIgnore;

@Data
@AllArgsConstructor
@NoArgsConstructor
@Builder
public class Teacher {

    private String id;
    private String username;

    @JsonIgnore
    private Set<GrantedAuthority> role;

}
