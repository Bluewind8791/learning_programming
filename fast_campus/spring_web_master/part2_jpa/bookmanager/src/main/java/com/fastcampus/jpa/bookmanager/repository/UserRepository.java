package com.fastcampus.jpa.bookmanager.repository;


import java.time.LocalDateTime;
import java.util.List;
import java.util.Map;
import java.util.Set;

import com.fastcampus.jpa.bookmanager.domain.User;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.domain.Sort;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.stereotype.Repository;


@Repository
public interface UserRepository extends JpaRepository<User, Long> {
    
    Set<User> findByName(String name);

    Set<User> findUserByNameIs(String name);
    Set<User> findUserByName(String name);
    Set<User> findUserByNameEquals(String name);

    User findByEmail(String email);
    User getByEmail(String email);
    User readByEmail(String email);
    User queryByEmail(String email);
    User searchByEmail(String email);
    User streamByEmail(String email);
    User findUserByEmail(String email);
    User findSomethingByEmail(String email);
    List<User> findFirst2ByName(String name);
    List<User> findTop2ByName(String name);
    List<User> findLast1ByName(String name);
    List<User> findByEmailAndName(String email, String name);
    List<User> findByEmailOrName(String email, String name);
    List<User> findByCreatedAtAfter(LocalDateTime yesterday);
    List<User> findByIdAfter(Long id);
    List<User> findByCreatedAtGreaterThan(LocalDateTime yesterday);
    List<User> findByCreatedAtGreaterThanEqual(LocalDateTime yesterday);
    List<User> findByCreatedAtBetween(LocalDateTime yesterday, LocalDateTime tomorrow);
    List<User> findByIdBetween(Long id1, Long id2);
    List<User> findByIdGreaterThanEqualAndIdLessThanEqual(Long id1, Long id2);
    List<User> findByIdIsNotNull();
    // List<User> findByAddressIsNotEmpty();   // name is not null and name != '' ??
    List<User> findByNameIn(List<String> names);
    List<User> findByNameStartingWith(String name);
    List<User> findByNameEndingWith(String name);
    List<User> findByNameContains(String name);
    List<User> findByNameLike(String name);
    List<User> findTop1ByName(String name);

    // 맨 위의 1개만 가져오는데 name을 통하여 검색할것이고 id 역순으로 정렬한다.
    List<User> findTop1ByNameOrderByIdDesc(String name); 
    List<User> findTopByNameOrderByIdDesc(String name);
    List<User> findFirstByNameOrderByIdDescEmailAsc(String name);
    List<User> findFirstByName(String name, Sort sort);

    // Page
    Page<User> findByName(String name, Pageable pageable);

    @Query(value = "select * from user limit 1;", nativeQuery = true) // query 그대로 실행
    Map<String, Object> findRawRecord();

    @Query(value = "select * from user", nativeQuery = true)
    List<Map<String, Object>> findAllRawRecord();
}
