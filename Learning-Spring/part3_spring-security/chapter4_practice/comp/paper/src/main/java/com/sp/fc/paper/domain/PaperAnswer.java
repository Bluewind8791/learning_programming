package com.sp.fc.paper.domain;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.persistence.*;
import java.io.Serializable;
import java.time.LocalDateTime;

import com.fasterxml.jackson.annotation.JsonIgnore;

@Data
@Entity
@Builder
@NoArgsConstructor
@AllArgsConstructor
@Table(name="sp_paper_answer")
public class PaperAnswer {

    @ManyToOne // 한 시험지에 많은 답안이 있다.
    @JsonIgnore
    @JoinColumn(foreignKey = @ForeignKey(name = "paperId"))
    Paper paper;

    @Data
    @Embeddable
    @NoArgsConstructor
    @AllArgsConstructor
    public static class PaperAnswerId implements Serializable {
        private Long paperId;
        private Integer num; // 1-base
    }

    @EmbeddedId
    private PaperAnswerId id;

    private Long problemId;

    private String answer;
    
    private boolean correct;

    private LocalDateTime answered; // updatable

    public Integer num(){
        return id.getNum();
    }

}
