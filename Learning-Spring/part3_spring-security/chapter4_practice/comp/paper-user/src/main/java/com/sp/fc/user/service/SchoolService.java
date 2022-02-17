package com.sp.fc.user.service;

import com.sp.fc.user.domain.School;
import com.sp.fc.user.repository.SchoolRepository;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import lombok.RequiredArgsConstructor;

import java.time.LocalDateTime;
import java.util.List;
import java.util.Optional;

@Service
@Transactional // db 작업
@RequiredArgsConstructor
public class SchoolService {

    private final SchoolRepository schoolRepository;

    public School save(School school){
        if (school.getSchoolId() == null){ // 만약 school 이 null 이라면 생성해야 하기 때문에
            school.setCreated(LocalDateTime.now()); // created 를 세팅하고
        }
        school.setUpdated(LocalDateTime.now()); // updated 를 세팅하고
        return schoolRepository.save(school); // save 친다
    }

    // school id 를 통하여 이름을 업데이트, 값이 없을수 있기때문에 optional
    public Optional<School> updateName(Long schoolId, String name){
        return schoolRepository.findById(schoolId).map(school -> {
            school.setName(name);
            schoolRepository.save(school);
            return school;
        });
    }

    public List<String> cities(){
        return schoolRepository.getCities();
    }

    public List<School> findAllByCity(String city) {
        return schoolRepository.findAllByCity(city);
    }

    public Optional<School> findSchool(Long schoolId) {
        return schoolRepository.findById(schoolId);
    }

    public Page<School> list(int pageNum, int size) {
        return schoolRepository.findAllByOrderByCreatedDesc(PageRequest.of(pageNum-1, size));
    }

    public List<School> getSchoolList(String city) {
        return schoolRepository.findAllByCity(city);
    }

    public long count() {
        return schoolRepository.count();
    }



}
