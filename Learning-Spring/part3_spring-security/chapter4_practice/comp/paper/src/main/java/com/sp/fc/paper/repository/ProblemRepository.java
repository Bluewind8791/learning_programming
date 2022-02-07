package com.sp.fc.paper.repository;

import java.time.LocalDateTime;
import java.util.List;

import com.sp.fc.paper.domain.Problem;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Modifying;
import org.springframework.data.jpa.repository.Query;

public interface ProblemRepository extends JpaRepository<Problem, Long> {

    // paper template id 로 find all, index num 으로 asc 정렬
    List<Problem> findAllByPaperTemplateIdOrderByIndexNumAsc(Long paperTemplateId);

    @Modifying
    @Query("update Problem set content=?2, answer=?3, updated=?4 where problemId=?1")
    void updateProblem(long problemId, String content, String answer, LocalDateTime now);
    
}
