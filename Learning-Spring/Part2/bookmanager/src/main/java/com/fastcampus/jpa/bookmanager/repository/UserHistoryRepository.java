package com.fastcampus.jpa.bookmanager.repository;

import java.util.List;

import com.fastcampus.jpa.bookmanager.domain.UserHistory;

import org.springframework.data.jpa.repository.JpaRepository;


public interface UserHistoryRepository extends JpaRepository<UserHistory, Long> {
    
    List<UserHistory> findByUserId(Long userId); // user id를 검색하여 user history를 불러옴
}
