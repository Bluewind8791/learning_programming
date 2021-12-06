package com.example.restaurant.naver.dto;

import org.springframework.util.LinkedMultiValueMap;
import org.springframework.util.MultiValueMap;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;


@Data
@NoArgsConstructor
@AllArgsConstructor
public class SearchImageReq {

    // naver 이미지 api 요청변수들 변수화
    private String query = "";          // string	Y	-
    private int display = 1;            // integer	N	10(기본값), 100(최대)
    private int start = 1;              // integer	N	1(기본값), 1000(최대)
    private String sort = "sim";        // string	N	string  정렬 옵션: sim (유사도순), date (날짜순)
    private String filter = "all";      // string	N	all (기본값),large, medium, small


    public MultiValueMap<String, String> toMultiValueMap() {
        var map = new LinkedMultiValueMap<String, String>();

        map.add("query", query);
        map.add("display", String.valueOf(display));
        map.add("start", String.valueOf(start));
        map.add("sort", sort);
        map.add("filter", filter);
        return map;
    }
}
