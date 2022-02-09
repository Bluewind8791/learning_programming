package com.sp.fc.user.service;

import com.sp.fc.user.domain.School;
import com.sp.fc.user.repository.SchoolRepository;
import com.sp.fc.user.service.helper.SchoolTestHelper;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.orm.jpa.DataJpaTest;

import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;


@DataJpaTest // db의 data를 넣고빼는 테스트 선언
public class SchoolTest {

    @Autowired // repository 는 datajpatest에서 자동으로 bean 을 만들어줌
    private SchoolRepository schoolRepository;

    private SchoolService schoolService; // sevice bean은 wiring이 안되기 때문에 before로 선언
    private SchoolTestHelper schoolTestHelper;
    School school;

    @BeforeEach
    void before(){
        this.schoolRepository.deleteAll(); // 시작하기전에 db clear
        this.schoolService = new SchoolService(schoolRepository); // schoolRepository 주입하여 생성
        this.schoolTestHelper = new SchoolTestHelper(this.schoolService); // helper 생성
        school = this.schoolTestHelper.createSchool("테스트 학교", "서울"); // helper 를 통한 학교 생성
    }


    @DisplayName("1. 학교를 생성한다.")
    @Test
    void test_1(){
        // -> 계속 반복되는 생성 구조는 helper 객체로 빼버린다
        // School school = School.builder()
        //                 .name("테스트 학교")
        //                 .city("서울")
        //                 .build();
        // schoolRepository.save(school);

        List<School> list = schoolRepository.findAll();
        assertEquals(1, list.size());
        // assertEquals("테스트 학교", list.get(0).getName());
        // assertEquals("서울", list.get(0).getCity());
        SchoolTestHelper.assertSchool(list.get(0), "테스트 학교", "서울");
    }

    @DisplayName("2. 학교 이름을 수정한다.")
    @Test
    void test_2() {
        schoolService.updateName(school.getSchoolId(), "테스트2 학교");
        assertEquals("테스트2 학교", schoolRepository.findAll().get(0).getName());
    }

    @DisplayName("3. 지역 목록을 가져온다.")
    @Test
    void test_3() {
        List<String> list = schoolService.cities();
        assertEquals(1, list.size());
        assertEquals("서울", list.get(0));

        schoolTestHelper.createSchool("부산 학교", "부산");
        list = schoolService.cities();
        assertEquals(2, list.size());
    }

    @DisplayName("4. 지역으로 학교 목록을 가져온다.")
    @Test
    void test_4() {
        List<School> list = schoolService.findAllByCity("서울");
        assertEquals(1, list.size());

        schoolTestHelper.createSchool("서울2 학교", "서울");
        list = schoolService.findAllByCity("서울");
        assertEquals(2, list.size());
    }
}
