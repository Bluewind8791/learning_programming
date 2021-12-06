package com.example.restaurant.wishlist.service;

import java.util.List;
import java.util.stream.Collectors;

import com.example.restaurant.naver.NaverClient;
import com.example.restaurant.naver.dto.SearchImageReq;
import com.example.restaurant.naver.dto.SearchLocalReq;
import com.example.restaurant.wishlist.dto.WishListDto;
import com.example.restaurant.wishlist.entity.WishListEntity;
import com.example.restaurant.wishlist.repository.WishListRepository;

import org.springframework.stereotype.Service;

import lombok.RequiredArgsConstructor;

@Service
@RequiredArgsConstructor
public class WishListService {
    
    private final NaverClient naverClient;
    private final WishListRepository wishListRepository;

    
    public WishListDto search(String query) {
        // 1. 지역 검색
        var searchLocalReq = new SearchLocalReq();
        searchLocalReq.setQuery(query);

        var searchLocalRes = naverClient.searchLocal(searchLocalReq);

        // 검색된 데이터가 있을 때
        if (searchLocalRes.getTotal() > 0) {
            var localItem = searchLocalRes.getItems().stream().findFirst().get(); // null pointer exception 안뜸 (> 0)
            
            var imageQuery = localItem.getTitle().replaceAll("<[^>]*>", ""); // 정규식 (이상한 특수문자 문자열 다 없애기)
            var searchImageReq = new SearchImageReq();
            searchImageReq.setQuery(imageQuery);

            // 2. 이미지 검색
            var searchImageRes = naverClient.searchImage(searchImageReq);

            if (searchImageRes.getTotal() > 0) {
                var imageItem = searchImageRes.getItems().stream().findFirst().get();

                // front 화면에 나타날 결과 return
                var result = new WishListDto();
                result.setTitle(localItem.getTitle());
                result.setCategory(localItem.getCategory());
                result.setAddress(localItem.getAddress());
                result.setRoadAddress(localItem.getRoadAddress());
                result.setHomepageLink(localItem.getLink());
                result.setImageLink(imageItem.getLink());

                return result;
            }
        } // end of if

        return new WishListDto();
    }// end of WishListDto search()


    public WishListDto add(WishListDto wishListDto) {
        var entity = dtoToEntity(wishListDto);
        var saveEntity = wishListRepository.save(entity);
        return entityToDto(saveEntity);
    }


    private WishListEntity dtoToEntity(WishListDto wishListDto) {
        var entity = new WishListEntity();
        entity.setIndex(wishListDto.getIndex());
        entity.setTitle(wishListDto.getTitle());
        entity.setCategory(wishListDto.getCategory());
        entity.setAddress(wishListDto.getAddress());
        entity.setRoadAddress(wishListDto.getRoadAddress());
        entity.setHomepageLink(wishListDto.getHomepageLink());
        entity.setImageLink(wishListDto.getImageLink());
        entity.setVisit(wishListDto.isVisit());
        entity.setVisitCount(wishListDto.getVisitCount());
        entity.setLastVisitDate(wishListDto.getLastVisitDate());
        return entity;
    }


    private WishListDto entityToDto(WishListEntity wishListEntity) {
        var dto = new WishListDto();
        dto.setIndex(wishListEntity.getIndex());
        dto.setTitle(wishListEntity.getTitle());
        dto.setCategory(wishListEntity.getCategory());
        dto.setAddress(wishListEntity.getAddress());
        dto.setRoadAddress(wishListEntity.getRoadAddress());
        dto.setHomepageLink(wishListEntity.getHomepageLink());
        dto.setImageLink(wishListEntity.getImageLink());
        dto.setVisit(wishListEntity.isVisit());
        dto.setVisitCount(wishListEntity.getVisitCount());
        dto.setLastVisitDate(wishListEntity.getLastVisitDate());
        return dto;
    }


    public List<WishListDto> findAll() {
        return wishListRepository.findAll()
            .stream()
            .map(it -> entityToDto(it)) // entity -> dto
            .collect(Collectors.toList()); // -> toList
    }

    // 특정 index 삭제
    public void delete(int index) {
        wishListRepository.deleteById(index);
    }


    public void addVisit(int index) {
        var wishItem = wishListRepository.findById(index);

        // 이 값이 있을때 업데이트
        if (wishItem.isPresent()) {
            var item = wishItem.get();

            item.setVisit(true);
            item.setVisitCount(item.getVisitCount() + 1);
        }
    }
}
