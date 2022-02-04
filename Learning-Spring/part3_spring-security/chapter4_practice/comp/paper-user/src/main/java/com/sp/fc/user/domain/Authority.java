package com.sp.fc.user.domain;

import lombok.Data;
import lombok.Builder;
import lombok.NoArgsConstructor;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.IdClass;
import javax.persistence.Table;

import org.springframework.security.core.GrantedAuthority;

import lombok.AllArgsConstructor;


@Data
@Entity
@Builder
@NoArgsConstructor
@AllArgsConstructor
@IdClass(Authority.class) // user 에게 중복된 authority 부여되면 안되기 때문에
@Table(name = "sp_authority")
public class Authority implements GrantedAuthority {

    public static final String ROLE_TEACHER = "ROLE_TEACHER";
    public static final String ROLE_STUDENT = "ROLE_STUDENT";

    @Id
    private Long userId;

    @Id
    private String authority;

    // @Override
    // public String getAuthority() {
    //     return null;
    // }
}
