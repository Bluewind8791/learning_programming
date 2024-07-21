package com.sp.fc.user.service;

import static org.junit.jupiter.api.Assertions.assertEquals;

import java.util.List;

import com.sp.fc.user.domain.User;
import com.sp.fc.user.service.helper.UserTestHelper;
import com.sp.fc.user.service.helper.WithUserTest;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.autoconfigure.orm.jpa.DataJpaTest;

/**
 * 학습자를 등록 한다.
 * 선생님을 등록하면 선생님의 학생으로 조회된다
 * 학교로 학생이 조회된다.
 */
@DataJpaTest
public class StudentTest extends WithUserTest {
    
    User student;
    User teacher;

    @BeforeEach
    void before() {
        prepareUserServices();
        this.teacher = this.userTestHelper.createTeacher(school, "teacher1");
        this.student = this.userTestHelper.createStudent(school, teacher, "student1", "grade1");
    }

    @DisplayName("1. 학습자를 등록한다.")
    @Test
    void test_1() {
        List<User> studentList = userService.findStudentList();
        assertEquals(1, studentList.size());
        UserTestHelper.assertStudent(school, teacher, studentList.get(0), "student1", "grade1");
    }

    @DisplayName("2. 선생님을 등록하면 선생님의 학생으로 조회된다")
    @Test
    void test_2() {
        List<User> studentList = userService.findTeacherStudentList(teacher.getUserId());
        assertEquals(1, studentList.size());
        UserTestHelper.assertStudent(school, teacher, studentList.get(0), "student1", "grade1");
    }

    @DisplayName("3. 학교로 학습자가 조회된다.")
    @Test
    void test_3 () {
        List<User> studentList = userService.findBySchoolStudentList(school.getSchoolId());
        assertEquals(1, studentList.size());
        UserTestHelper.assertStudent(school, teacher, studentList.get(0), "student1", "grade1");
    }



}
