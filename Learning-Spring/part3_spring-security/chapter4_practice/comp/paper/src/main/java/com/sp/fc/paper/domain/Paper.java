package com.sp.fc.paper.domain;


import lombok.Data;
import lombok.Builder;
import lombok.NoArgsConstructor;
import lombok.AllArgsConstructor;

import java.time.LocalDateTime;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;

import javax.persistence.CascadeType;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.OneToMany;
import javax.persistence.Table;
import javax.persistence.Transient;

import com.sp.fc.user.domain.User;



@Data
@Entity
@Builder
@NoArgsConstructor
@AllArgsConstructor
@Table(name = "sp_paper")
public class Paper {
    

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long paperId;

    private Long paperTemplateId;

    private String name;

    private Long studentUserId;

    @Transient // 영속화 X
    private User user;

    // 한개의 시험지는 여러개의 답안을 가지고 있다 / 연관관계 주인이 아님
    @OneToMany(fetch = FetchType.LAZY, cascade = CascadeType.ALL, orphanRemoval = true, mappedBy = "paper")
    private List<PaperAnswer> paperAnswerList;

    private LocalDateTime created;
    private LocalDateTime startTime;
    private LocalDateTime endTime;

    private PaperState state;

    public static enum PaperState {
        READY,
        START,
        END,
        CANCELED
    }

    private int total;
    private int answered;
    private int correct;

    @Transient
    public double getScore() {
        if (total < 1) {
            return 0;
        }
        return correct * 100.0 / total;
    }

    public void addAnswerd() {
        answered++;
    }

    public void addCorrect() {
        correct++;
    }

    public Map<Integer, PaperAnswer> answerMap() {
        if (paperAnswerList == null) {
            return new HashMap<>();
        }
        return paperAnswerList.stream().collect(Collectors.toMap(PaperAnswer::num, 
            Function.identity()
        ));
    }




}
