package com.sp.fc.paper.repository;

import java.util.List;

import com.sp.fc.paper.domain.Paper;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.jpa.repository.JpaRepository;


public interface PaperRepository extends JpaRepository<Paper, Long> {
    
    // paper template id 와 student user id로 모두 찾기
    List<Paper> findAllByPaperTemplateIdAndStudentUserIdIn(Long paperTemplateId, List<Long> studentIdList);

    // paper template id 로 모두 찾기
    List<Paper> findAllByPaperTemplateId(Long paperTemplateId);
    long countByPaperTemplateId(Long paperTemplateId);

    // student user id 로 모두 찾고, 생성일자에 따라 desc 정렬
    List<Paper> findAllByStudentUserIdOrderByCreatedDesc(Long studentUserId);
    long countByStudentUserId(Long studentUserId);

    // student user id 와 state(상태)로 모두 찾고, 생성일자에 따라 desc 정렬
    List<Paper> findAllByStudentUserIdAndStateOrderByCreatedDesc(Long studentUserId, Paper.PaperState state);
    Page<Paper> findAllByStudentUserIdAndStateOrderByCreatedDesc(Long studentUserId, Paper.PaperState state, Pageable pageable);
    long countByStudentUserIdAndState(Long studentUserId, Paper.PaperState state);

    // student user id 와 state들로 모두 찾고, 생성일자에 따라 desc 정렬
    List<Paper> findAllByStudentUserIdAndStateInOrderByCreatedDesc(Long studyUserId, List<Paper.PaperState> states);
    long countByStudentUserIdAndStateIn(Long studyUserId, List<Paper.PaperState> states);
    

}
