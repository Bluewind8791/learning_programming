package com.sp.fc.user.repository;

import com.sp.fc.user.domain.School;

import java.util.List;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;


public interface SchoolRepository extends JpaRepository<School, Long> {

    @Query("select distinct(city) from School") // DISTINCT 중복제거
    List<String> getCities();

    List<School> findAllByCity(String city);

    Page<School> findAllByOrderByCreatedDesc(Pageable pageable);

}
