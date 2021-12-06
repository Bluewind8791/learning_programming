package com.example.restaurant.naver;

import com.example.restaurant.naver.dto.SearchImageReq;
import com.example.restaurant.naver.dto.SearchLocalReq;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import lombok.extern.slf4j.Slf4j;

@Slf4j
@SpringBootTest
public class NaverClientTest {
    
    @Autowired
    private NaverClient naverClient;


    @Test
    public void searchLocalTest() {
        var search = new SearchLocalReq();
        search.setQuery("갈비집"); // example

        var result = naverClient.searchLocal(search);
        log.info(String.valueOf(result));
        Assertions.assertNotNull(result.getItems().stream().findFirst().get().getCategory());
    }


    @Test
    public void searchImageTest() {
        var search = new SearchImageReq();
        search.setQuery("갈비집"); // example

        var result = naverClient.searchImage(search);
        log.info(String.valueOf(result));
    }
}
