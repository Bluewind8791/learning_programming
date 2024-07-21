package com.sp.fc.user.domain;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.IdClass;
import javax.persistence.Table;

import org.springframework.security.core.GrantedAuthority;

import lombok.Data;
import lombok.Builder;
import lombok.NoArgsConstructor;
import lombok.AllArgsConstructor;


@Data
@NoArgsConstructor
@AllArgsConstructor
@Builder
@Entity // DB Table
@IdClass(SpAuthority.class)
@Table(name = "sp_user_authority") // table name
public class SpAuthority implements GrantedAuthority {

    @Id // pk
    @Column(name = "user_id")
    private Long userId;

    @Id
    private String authority;

}
