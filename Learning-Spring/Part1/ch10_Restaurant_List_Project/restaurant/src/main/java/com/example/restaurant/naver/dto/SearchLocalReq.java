package com.example.restaurant.naver.dto;

import org.springframework.util.LinkedMultiValueMap;
import org.springframework.util.MultiValueMap;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;


@Data
@NoArgsConstructor
@AllArgsConstructor
public class SearchLocalReq {

    // naver 지역 api 요청변수들 변수화
    private String query = "";          // query	string	Y	-
    private int display = 1;            // display	integer	N	1(기본값), 5(최대)
    private int start = 1;              // start	integer	N	1(기본값), 1(최대)
    private String sort = "random";     // sort	    string	N	random (기본값), comment

    public MultiValueMap<String, String> toMultiValueMap() {
        var map = new LinkedMultiValueMap<String, String>();

        map.add("query", query);
        map.add("display", String.valueOf(display));
        map.add("start", String.valueOf(start));
        map.add("sort", sort);
        return map;
    }
}
