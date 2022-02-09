package com.sp.fc.paper.domain;

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
@Table(name = "sp_problem")
public class Problem {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long problemId;

    private Long paperTemplateId; // PaperTemplate 의 FK

    private int indexNum; // 1-based

    private String content;

    private String answer;

    @Column(updatable = false)
    private LocalDateTime created;

    private LocalDateTime updated;

}
