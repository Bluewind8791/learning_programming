package com.fastcampus.jpa.bookmanager.repository;


import java.util.List;

import com.fastcampus.jpa.bookmanager.domain.User;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.domain.Sort;
import org.springframework.data.jpa.repository.JpaRepository;



public interface UserRepository extends JpaRepository<User, Long> {
    
    // 맨 위의 1개만 가져오는데 name을 통하여 검색할것이고 id 역순으로 정렬한다.
    List<User> findTop1ByNameOrderByIdDesc(String name); 

    List<User> findFirstByNameOrderByIdDesc(String name);
    List<User> findFirstByNameOrderByIdDescEmailAsc(String name);

    List<User> findFirstByName(String name, Sort sort);


    // Page
    Page<User> findByName(String name, Pageable pageable);
}
