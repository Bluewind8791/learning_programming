package com.sp.fc.paper.domain;

import com.sp.fc.user.domain.User;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.persistence.*;
import java.time.LocalDateTime;
import java.util.List;

// teacher 가 작성하는 paper(시험지)
@Data
@Entity
@Builder
@NoArgsConstructor
@AllArgsConstructor
@Table(name="sp_paper_template")
public class PaperTemplate {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long paperTemplateId;

    private String name;

    private Long userId;

    @Transient // 영속성 X 필요시에만 꽂아줌
    private User creator;

    // 총 문제 갯수 - 매번 조회시마다 problemList를 가져오는것은 부담스럽기 때문에 지정
    private int total;

    @OneToMany(fetch = FetchType.LAZY, cascade = CascadeType.ALL)
    @JoinColumn(foreignKey = @ForeignKey(name="paperTemplateId"))
    private List<Problem> problemList;

    private long publishedCount;

    private long completeCount;

    @Column(updatable = false)
    private LocalDateTime created;

    private LocalDateTime updated;

}
