package com.fastcampus.jpa.bookmanager.domain;

import java.time.LocalDateTime;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.EnumType;
import javax.persistence.Enumerated;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;
import lombok.NonNull;


// import lombok.RequiredArgsConstructor;
// @RequiredArgsConstructor 
//      - 꼭 필요한 인자만을 이용하여 생성자를 만들어줌 (@NonNull 생성자 있는 두개)
//      - @Data에 포함되어있음

@Data
@Builder
@Entity
@NoArgsConstructor // 거의 필수급
@AllArgsConstructor
public class User {

    @Id
    @GeneratedValue
    private Long id;

    @NonNull
    private String name;

    @NonNull
    private String email;

    @Enumerated(value = EnumType.STRING)
    private Gender gender;

    @Column(updatable = false)
    private LocalDateTime createAt;

    private LocalDateTime updateAt;

    // @Transient
    // private String testData;

    // @OneToMany(fetch = FetchType.EAGER)
    // private List<Address> address;
}
