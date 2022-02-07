package com.sp.fc.paper.repository;

import java.util.List;

import com.sp.fc.paper.domain.PaperTemplate;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.jpa.repository.JpaRepository;

public interface PaperTemplateRepository extends JpaRepository<PaperTemplate, Long> {
    
    // user id 로 find all, 생성일자로 desc 정렬
    List<PaperTemplate> findAllByUserIdOrderByCreatedDesc(Long userId);
    Page<PaperTemplate> findAllByUserIdOrderByCreatedDesc(Long userId, Pageable pageable);

    long countByuserId(Long userId);
}
