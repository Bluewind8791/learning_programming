package com.example.restaurant.wishlist.entity;

import java.time.LocalDateTime;

import com.example.restaurant.db.MemoryDbEntity;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.NoArgsConstructor;


@AllArgsConstructor
@NoArgsConstructor
@Data
@EqualsAndHashCode(callSuper = false)
public class WishListEntity extends MemoryDbEntity {
    
    private String title; // 음식명, 장소명
    private String category; // 카테고리
    private String address; // 주소명
    private String roadAddress; // 도로명주소
    private String homepageLink; // 홈페이지 링크
    private String imageLink;   // 이미지 링크
    private boolean isVisit;    // 방문 여부
    private int visitCount; // 방문 횟수
    private LocalDateTime lastVisitDate; // 최근 방문 일자
}
