package com.sp.fc.web;

import com.sp.fc.web.paper.Paper;
import com.sp.fc.web.paper.PaperRepository;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.cache.CacheManager;

import java.util.Optional;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;

@SpringBootTest(classes = AuthorityACLApplication.class)
public class CacheTest {

    @Autowired
    private PaperRepository paperRepository;

    @Autowired
    private CacheManager cacheManager;

    Optional<Paper> getPaperFromCache(Long id){
        // paperRepository.findById에 papers 이름으로 cache 등록
        return Optional.ofNullable(cacheManager.getCache("papers").get(id, Paper.class));
    }

    @DisplayName("1. 조회한 Paper는 cahce에 등록된다.")
    @Test
    void test_() {
        Paper paper1 = Paper.builder().id(1L).title("paper1").build();

        paperRepository.save(paper1);
        assertEquals(Optional.empty(), getPaperFromCache(1L));

        paperRepository.findById(1L);
        assertTrue(getPaperFromCache(1L).isPresent());
    }

}
