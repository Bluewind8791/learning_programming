package com.fastcampus.jpa.bookmanager.domain;

import java.util.ArrayList;
import java.util.List;

import javax.persistence.Entity;
import javax.persistence.EntityListeners;
import javax.persistence.EnumType;
import javax.persistence.Enumerated;
import javax.persistence.FetchType;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.OneToMany;

import com.fastcampus.jpa.bookmanager.domain.listener.UserEntityListener;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.NoArgsConstructor;
import lombok.NonNull;
import lombok.RequiredArgsConstructor;
import lombok.ToString;


// import lombok.RequiredArgsConstructor;
// @RequiredArgsConstructor 
//      - 꼭 필요한 인자만을 이용하여 생성자를 만들어줌 (@NonNull 생성자 있는 두개)
//      - @Data에 포함되어있음

// @Table(name = "user", indexes = {@Index(columnList = "name")}, uniqueConstraints = {@UniqueConstraint(columnNames = {"email"})})


@NoArgsConstructor // 거의 필수급
@AllArgsConstructor
@RequiredArgsConstructor
@Data
@Builder
@Entity
@EntityListeners(value = {UserEntityListener.class})
@ToString(callSuper = true)
@EqualsAndHashCode(callSuper = true)
public class User extends BaseEntity {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @NonNull
    private String name;

    @NonNull
    private String email;

    @Enumerated(value = EnumType.STRING)
    private Gender gender;

    @OneToMany(fetch = FetchType.EAGER) // LazyInitializationException
    @JoinColumn(name = "user_id", insertable = false, updatable = false)
    @Builder.Default
    private List<UserHistory> userHistories = new ArrayList<>();

    @OneToMany
    @JoinColumn(name = "user_id")
    @ToString.Exclude
    @Builder.Default
    private List<Review> reviews = new ArrayList<>();
}
