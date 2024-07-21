package com.sp.fc.user.service;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.StreamSupport;

import com.sp.fc.user.domain.Authority;
import com.sp.fc.user.domain.User;
import com.sp.fc.user.service.helper.UserTestHelper;
import com.sp.fc.user.service.helper.WithUserTest;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.autoconfigure.orm.jpa.DataJpaTest;
import org.springframework.dao.DataIntegrityViolationException;


/**
 * 사용자 생성
 * 이름 수정
 * 권한 부여
 * 권한 취소
 * 이메일 검색
 * ROLE 중복해서 추가 X
 * 이메일이 중복해서 들어가는가?
 */
@DataJpaTest
public class UserTest extends WithUserTest {
    
    @BeforeEach
    protected void before() {
        prepareUserServices();
    }

    @DisplayName("1. 사용자 생성")
    @Test
    void test_1() {
        userTestHelper.createUser(school, "user1");
        List<User> list = StreamSupport.stream(userRepository.findAll().spliterator(), false)
                .collect(Collectors.toList());
        assertEquals(1, list.size());
        UserTestHelper.assertUser(school, list.get(0), "user1");
    }

    @DisplayName("2. 이름 수정")
    @Test
    void test_2() {
        User user = userTestHelper.createUser(school, "user1");
        userService.updateUsername(user.getUserId(), "user2");
        List<User> list = StreamSupport.stream(userRepository.findAll().spliterator(), false).collect(Collectors.toList());
        assertEquals("user2", list.get(0).getName());
    }

    @DisplayName("3. 권한 부여")
    @Test
    void test_3() {
        User user = userTestHelper.createUser(school, "user1", Authority.ROLE_STUDENT); // student 권한의 user1 을 만들고
        userService.addAuthority(user.getUserId(), Authority.ROLE_TEACHER); // teacher 권한을 추가
        User savedUser = userService.findUser(user.getUserId()).get(); // find user
        
        UserTestHelper.assertUser(school, savedUser, "user1", Authority.ROLE_STUDENT, Authority.ROLE_TEACHER); // 두개의 권한이 있는지 검사
    }

    @DisplayName("4. 권한 취소")
    @Test
    void test_4() {
        User user1 = userTestHelper.createUser(school, "admin", Authority.ROLE_STUDENT, Authority.ROLE_TEACHER);
        userService.removeAuthority(user1.getUserId(), Authority.ROLE_STUDENT);
        User savedUser = userService.findUser(user1.getUserId()).get();
        UserTestHelper.assertUser(school, savedUser, "admin", Authority.ROLE_TEACHER);
    }

    @DisplayName("5. E-mail 검색")
    @Test
    void test_5() {
        userTestHelper.createUser(school, "user1");
        User savedUser = (User)userSecurityService.loadUserByUsername("user1@test.com");
        UserTestHelper.assertUser(school, savedUser, "user1");
    }

    @DisplayName("6. ROLE이 중복되어 추가되지 않는다.")
    @Test
    void test_6() {
        User user1 = userTestHelper.createUser(school, "user1", Authority.ROLE_STUDENT);
        userService.addAuthority(user1.getUserId(), Authority.ROLE_STUDENT);
        userService.addAuthority(user1.getUserId(), Authority.ROLE_STUDENT); // 권한 중복 부여

        User savedUser = userService.findUser(user1.getUserId()).get();
        assertEquals(1, savedUser.getAuthorities().size());
        UserTestHelper.assertUser(school, savedUser, "user1", Authority.ROLE_STUDENT);
    }

    @DisplayName("7. E-mail이 중복되어 회원가입되는가?")
    @Test
    void test_7() {
        userTestHelper.createUser(school, "user1");
        // 같은 user1 이름으로 만들었을때 아래와 같은 exception이 발생해야 함
        assertThrows(DataIntegrityViolationException.class, () -> {
            userTestHelper.createUser(school, "user1");
        });
    }



}

