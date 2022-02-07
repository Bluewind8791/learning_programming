package com.sp.fc.paper.domain;



import lombok.Data;
import lombok.Builder;
import lombok.NoArgsConstructor;

import java.io.Serializable;
import java.time.LocalDateTime;

import javax.persistence.Embeddable;
import javax.persistence.EmbeddedId;
import javax.persistence.Entity;
import javax.persistence.ForeignKey;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.Table;

import com.fasterxml.jackson.annotation.JsonIgnore;

import lombok.AllArgsConstructor;


@Data
@Entity
@Builder
@NoArgsConstructor
@AllArgsConstructor
@Table(name = "sp_paper_answer")
public class PaperAnswer {

    @EmbeddedId // ?
    private PaperAnswerId id;

    @Data
    @Embeddable // ?
    @NoArgsConstructor
    @AllArgsConstructor
    public static class PaperAnswerId implements Serializable { // Serializable
        private Long paperId;
        private Integer num; // 1-base
    }

    private Long problemId;
    private String answer;
    private boolean correct;
    private LocalDateTime answerd; // updateable

    // 답안은 한 시험지에 여러개 있다.
    @JsonIgnore // 
    @ManyToOne
    @JoinColumn(foreignKey = @ForeignKey(name = "paperId"))
    Paper paper;

    public Integer num() {
        return id.getNum();
    }



}