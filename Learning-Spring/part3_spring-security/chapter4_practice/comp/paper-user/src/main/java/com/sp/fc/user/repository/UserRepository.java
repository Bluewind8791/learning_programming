package com.sp.fc.user.repository;

import java.time.LocalDateTime;
import java.util.List;
import java.util.Optional;

import com.sp.fc.user.domain.User;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Modifying;
import org.springframework.data.jpa.repository.Query;

public interface UserRepository extends JpaRepository<User, Long> {
    
    @Modifying(clearAutomatically = true)
    @Query("update User set name=?2, updated=?3 where userId=?1")
    void updateUserName(Long userId, String userName, LocalDateTime update);

    Optional<User> findByEmail(String username);

    // 권한이 ROLE 의 역할도 겸하고 있기때문에 권한을 통하여 검색하는 메소드
    @Query("select a from User a, Authority b where a.userId=b.userId and b.authority=?1")
    List<User> findAllByAuthoritiesIn(String authority);

    // UI 를 위하여 paging 된 리스트
    @Query("select a from User a, Authority b where a.userId=b.userId and b.authority=?1")
    Page<User> findAllByAuthoritiesIn(String authority, Pageable pageable);

    // 학교 id 를 통한 검색
    @Query("select a from User a, Authority b where a.school.schoolId=?1 and a.userId=b.userId and b.authority=?2")
    List<User> findAllBySchool(Long schoolId, String authority);

    // 선생님 id 를 통하여 그 선생님의 학생들 찾기
    @Query("select a from User a, User b where a.teacher.userId=b.userId and b.userId=?1")
    List<User> findAllByTeacherUserId(Long userId);

    @Query("select count(a) from User a, User b where a.teacher.userId=b.userId and b.userId=?1")
    Long countByAllTeacherUserId(Long userId);

    @Query("select count(a) from User a, Authority b where a.userId=b.userId and b.authority=?1")
    Long countAllByAuthoritiesIn(String authority);

    @Query("select count(a) from User a, Authority b where a.school.schoolId=?1 and a.userId=b.userId and b.authority=?2")
    Long countAllByAuthoritiesIn(Long schoolId, String authority);


}
