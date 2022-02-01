package com.sp.fc.web.paper;

import javax.persistence.Entity;
import javax.persistence.Id;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@Entity
@Builder
@NoArgsConstructor
@AllArgsConstructor
public class Paper {

    @Id
    private Long id;
    private String title;
    private String tutorId;
    private State state;

    public static enum State {
        PREPARE, // 출제 중
        READY,  // 시험 시작
        END  // 시험 종료
    }

}
