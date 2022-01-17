package com.example.restaurant.naver.dto;

import java.util.List;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;


@Data
@NoArgsConstructor
@AllArgsConstructor
public class SearchImageRes {
    
    // naver 이미지 api 출력 결과
    private String lastBuildDate = "";          // datetime	검색 결과를 생성한 시간이다.
    private int total;                          // integer	검색 결과 문서의 총 개수를 의미한다.
    private int start;                          // integer	검색 결과 문서 중, 문서의 시작점을 의미한다.
    private int display;                        // integer	검색된 검색 결과의 개수이다.
    private List<SearchLocalItem> items;        // XML 포멧에서는 item 태그로, JSON 포멧에서는 items 속성으로 표현된다. 개별 검색 결과이며 title, link, description, address, mapx, mapy를 포함한다.


    // 내부클래스
    @Data
    @NoArgsConstructor
    @AllArgsConstructor
    public static class SearchLocalItem {
        private String title;         // string	검색 결과 업체, 기관명을 나타낸다.
        private String link;          // string	검색 결과 업체, 기관의 상세 정보가 제공되는 네이버 페이지의 하이퍼텍스트 link를 나타낸다.
        private String thumbnail;     // string	검색 결과 이미지의 썸네일 link를 나타낸다.
        private String sizeheight;    // string	검색 결과 이미지의 썸네일 높이를 나타낸다.
        private String sizewidth;     // string	검색 결과 이미지의 너비를 나타낸다. 단위는 pixel이다.
    }
}
