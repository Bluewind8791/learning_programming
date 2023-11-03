package com.sp.fc.user.domain;

import lombok.Data;
import lombok.Builder;
import lombok.NoArgsConstructor;

import java.util.Objects;

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

    public static final String ROLE_ADMIN = "ROLE_ADMIN";
    public static final String ROLE_TEACHER = "ROLE_TEACHER";
    public static final String ROLE_STUDENT = "ROLE_STUDENT";

    public static final Authority ADMIN_AUTHORITY = Authority.builder().authority(ROLE_ADMIN).build();
    public static final Authority TEACHER_AUTHORITY = Authority.builder().authority(ROLE_TEACHER).build();
    public static final Authority STUDENT_AUTHORITY = Authority.builder().authority(ROLE_STUDENT).build();

    @Id
    private Long userId;

    @Id
    private String authority;

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (!(obj instanceof Authority)) return false;
        Authority authorityObj = (Authority) obj;
        return Objects.equals(authority, authorityObj.authority);
    }

    @Override
    public int hashCode() {
        return Objects.hash(authority);
    }

}
