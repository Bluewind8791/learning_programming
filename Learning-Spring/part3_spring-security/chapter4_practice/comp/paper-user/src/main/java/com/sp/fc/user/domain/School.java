package com.sp.fc.user.domain;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.persistence.*;
import java.time.LocalDateTime;

@Data
@Entity
@Builder
@NoArgsConstructor
@AllArgsConstructor
@Table(name="sp_school") // table name
public class School {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long schoolId;

    private String name;

    private String city;

    @Transient
    private Long teacherCount;

    @Transient
    private Long studyCount;

    @Column(updatable = false) // update 안되게 설정
    private LocalDateTime created;

    private LocalDateTime updated;

}
