package com.example.restaurant.naver.dto;

import java.util.List;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;


@Data
@NoArgsConstructor
@AllArgsConstructor
public class SearchLocalRes {
    
    // naver 지역 api 출력 결과
    private String lastBuildDate = "";   // datetime    검색 결과를 생성한 시간이다.
    private int total;                   // integer     검색 결과 문서의 총 개수를 의미한다.
    private int start;                   // integer	    검색 결과 문서 중, 문서의 시작점을 의미한다.
    private int display;                 // integer	    검색된 검색 결과의 개수이다.
    private List<SearchLocalItem> items; // XML 포멧에서는 item 태그로, JSON 포멧에서는 items 속성으로 표현된다. 개별 검색 결과이며 title, link, description, address, mapx, mapy를 포함한다.


    // 내부클래스
    @Data
    @NoArgsConstructor
    @AllArgsConstructor
    public static class SearchLocalItem {
        
        private String category;        // string	검색 결과 업체, 기관의 분류 정보를 제공한다. (naver api document 오류)
        private String title;           // string	검색 결과 업체, 기관명을 나타낸다.
        private String link;            // string	검색 결과 업체, 기관의 상세 정보가 제공되는 네이버 페이지의 하이퍼텍스트 link를 나타낸다.
        private String description;     // string	검색 결과 업체, 기관명에 대한 설명을 제공한다.
        private String telephone;       // string	빈 문자열 반환. 과거에 제공되던 항목이라 하위 호환성을 위해 존재한다.
        private String address;         // string	검색 결과 업체, 기관명의 주소를 제공한다.
        private String roadAddress;     // string	검색 결과 업체, 기관명의 도로명 주소를 제공한다.
        private int mapx;               // integer	검색 결과 업체, 기관명 위치 정보의 x좌표를 제공한다. 제공값은 카텍좌표계 값으로 제공된다. 이 좌표값은 지도 API와 연동 가능하다.
        private int mapy;               // integer	검색 결과 업체, 기관명 위치 정보의 y좌표를 제공한다. 제공값은 카텍 좌표계 값으로 제공된다. 이 좌표값은 지도 API와 연동 가능하다.
    }
}
