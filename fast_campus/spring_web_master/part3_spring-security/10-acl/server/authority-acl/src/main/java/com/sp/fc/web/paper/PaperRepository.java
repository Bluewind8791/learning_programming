package com.sp.fc.web.paper;

import java.util.Optional;

// import org.springframework.cache.annotation.Cacheable;
import org.springframework.data.jpa.repository.JpaRepository;

public interface PaperRepository extends JpaRepository<Paper, Long> {
    
    // @Cacheable(value = "papers")
    Optional<Paper> findById(Long id);

    
}
