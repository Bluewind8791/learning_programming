package com.sp.fc.web;

import static org.junit.jupiter.api.Assertions.assertEquals;

import java.util.List;

import com.sp.fc.web.service.Paper;
import com.sp.fc.web.service.PaperService;
import com.sp.fc.web.test.WebIntegrationTest;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.web.client.TestRestTemplate;
import org.springframework.core.ParameterizedTypeReference;
import org.springframework.http.HttpMethod;
import org.springframework.http.ResponseEntity;

public class PaperTest extends WebIntegrationTest {

    @Autowired
    private PaperService paperService;

    TestRestTemplate client = new TestRestTemplate();

    private Paper paper1 = Paper.builder()
        .paperId(1L)
        .title("시험지1")
        .tutorId("tutor1")
        .studentIds(List.of("user1"))
        .state(Paper.State.PREPARE)
        .build();

    private Paper paper2 = Paper.builder()
        .paperId(2L)
        .title("시험지2")
        .tutorId("tutor1")
        .studentIds(List.of("user2"))
        .state(Paper.State.READY)
        .build();

    private Paper paper3 = Paper.builder()
        .paperId(3L)
        .title("시험지3")
        .tutorId("tutor1")
        .studentIds(List.of("user1"))
        .state(Paper.State.READY)
        .build();



    @DisplayName("3. 본인의 시험지라도 출제중이면 접근 불가")
    @Test
    void test_3() {
        paperService.setPaper(paper2);

        client = new TestRestTemplate("user2", "1111");
        ResponseEntity<Paper> response = client.exchange(uri("/paper/get/2"), 
            HttpMethod.GET, null, new ParameterizedTypeReference<Paper>() {
            });
        
        assertEquals(403, response.getStatusCodeValue());
    }




    @DisplayName("2. 본인(user1)이 아닌 다른 유저(user2)의 시험지 접근 불가")
    @Test
    void test_2() {
        paperService.setPaper(paper2);

        client = new TestRestTemplate("user1", "1111");
        ResponseEntity<Paper> response = client.exchange(uri("/paper/get/2"), 
            HttpMethod.GET, null, new ParameterizedTypeReference<Paper>() {
            });
        
        assertEquals(403, response.getStatusCodeValue());
    }


    @DisplayName("1. user1 시험지 리스트 조회")
    @Test
    void test_1() {
        paperService.setPaper(paper1);
        paperService.setPaper(paper2);
        paperService.setPaper(paper3);

        client = new TestRestTemplate("user1", "1111");
        ResponseEntity<List<Paper>> response = client.exchange(uri("/paper/mypapers"), 
            HttpMethod.GET, null, new ParameterizedTypeReference<List<Paper>>() {
            });

        assertEquals(200, response.getStatusCodeValue());
        assertEquals(2, response.getBody().size());
        System.out.println(response.getBody());
    }



}
