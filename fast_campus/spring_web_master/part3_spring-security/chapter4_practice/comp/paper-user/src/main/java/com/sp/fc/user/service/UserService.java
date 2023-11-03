package com.sp.fc.user.service;

import java.time.LocalDateTime;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.StreamSupport;

import com.sp.fc.user.domain.Authority;
import com.sp.fc.user.domain.User;
import com.sp.fc.user.repository.SchoolRepository;
import com.sp.fc.user.repository.UserRepository;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import lombok.RequiredArgsConstructor;

@Service
@Transactional
@RequiredArgsConstructor
public class UserService {
    
    private final SchoolRepository schoolRepository;
    private final UserRepository userRepository;

    public User save(User user) {
        if (user.getUserId() == null) {
            user.setCreated(LocalDateTime.now());
        }
        user.setUpdated(LocalDateTime.now());
        return userRepository.save(user);
    }

    public Optional<User> findUser(Long userId) {
        return userRepository.findById(userId);
    }

    public Page<User> listUser(int pageNum, int size) {
        return userRepository.findAll(PageRequest.of(pageNum - 1, size));
    }

    // userId를 검색하여 유저 객체들을 리스트로 뽑아냄
    public Map<Long, User> getUsers(List<Long> userIds) { // spliteraotr : 더이상 splitting이 필요하지 않을때 특정 action을 하는 함수
        return StreamSupport.stream(userRepository.findAllById(userIds).spliterator(), false) // parallel 병렬처리 false
                .collect(Collectors.toMap(User::getUserId, Function.identity()));
    }

    // 권한 추가 메소드
    public void addAuthority(Long userId, String authority) {
        // user repo 에서 id를 통하여 user를 찾고 있는 유저라면 ->
        userRepository.findById(userId).ifPresent(user -> {
            Authority newRole = new Authority(user.getUserId(), authority); // new role 객체를 생성하고
            if (user.getAuthorities() == null) { // 만약 유저가 권한이 아무것도 없다면
                HashSet<Authority> authorities = new HashSet<>(); // HashMap 타입(중복방지)의 새로운 권한을 생성하고
                authorities.add(newRole); // newRole 권한을 추가
                user.setAuthorities(authorities); // 유저에 권한을 추가한다.
                save(user);
            } else if (!user.getAuthorities().contains(newRole)) { // 만약 유저가 newRole 권한을 가지고있지않다면
                HashSet<Authority> authorities = new HashSet<>();
                authorities.addAll(user.getAuthorities());
                authorities.add(newRole);
                user.setAuthorities(authorities);
                save(user);
            }
        });
    }


    public void removeAuthority(Long userId, String authority) {
        userRepository.findById(userId).ifPresent(user -> {
            if (user.getAuthorities() == null) return; // user 에게 권한이 없다면 종료
            Authority targetRole = new Authority(user.getUserId(), authority); // 삭제 target role 객체 생성
            if (user.getAuthorities().contains(targetRole)) { // 만약 user이 target role을 가지고 있다면
                user.setAuthorities( // target role을 제외한 권한을 부여
                    user.getAuthorities().stream().filter(auth -> !auth.equals(targetRole)) 
                                                          .collect(Collectors.toSet())
                );
                save(user);
            }
        });
    }

    public void updateUsername(Long userId, String userName) {
        userRepository.updateUserName(userId, userName, LocalDateTime.now());
    }

    public Optional<User> findByEmail(String email) {
        return userRepository.findByEmail(email);
    }

    public List<User> findTeacherList() {
        return userRepository.findAllByAuthoritiesIn(Authority.ROLE_TEACHER);
    }

    public List<User> findStudentList() {
        return userRepository.findAllByAuthoritiesIn(Authority.ROLE_STUDENT);
    }

    public List<User> findTeacherStudentList(Long userId) {
        return userRepository.findAllByTeacherUserId(userId);
    }

    public Long findTeacherStudentCount(Long userId) {
        return userRepository.countByAllTeacherUserId(userId);
    }

    public List<User> findBySchoolStudentList(Long schoolId) {
        return userRepository.findAllBySchool(schoolId, Authority.ROLE_STUDENT);
    }

    public List<User> findBySchoolTeacherList(Long schoolId) {
        return userRepository.findAllBySchool(schoolId, Authority.ROLE_TEACHER);
    }

    // 소속 변경 method
    public void updateUserSchoolTeacher(Long userId, Long schoolId, Long teacherId) {
        userRepository.findById(userId).ifPresent(user -> {
            if (!user.getSchool().getSchoolId().equals(schoolId)) { // school id 가 다르다면
                schoolRepository.findById(schoolId).ifPresent(school -> user.setSchool(school));
            }
            if (!user.getTeacher().getUserId().equals(teacherId)) { // teacher id 가 다르다면
                findUser(teacherId).ifPresent(teacher -> user.setTeacher(teacher));
            }
            if (user.getSchool().getSchoolId() != user.getTeacher().getSchool().getSchoolId()) { // 설정한 선생의 학교가 동일하지 않다면
                throw new IllegalArgumentException("해당 학교의 선생님이 아닙니다.");
            }
            save(user);
        });
    }

    public long countTeacher() {
        return userRepository.countAllByAuthoritiesIn(Authority.ROLE_TEACHER);
    }
    public long countTeacher(long schoolId) {
        return userRepository.countAllByAuthoritiesIn(schoolId, Authority.ROLE_TEACHER);
    }

    public long countStudent() {
        return userRepository.countAllByAuthoritiesIn(Authority.ROLE_STUDENT);
    }
    public long countStudent(long schoolId) {
        return userRepository.countAllByAuthoritiesIn(schoolId, Authority.ROLE_STUDENT);
    }

    public Page<User> listStudents(Integer pageNum, Integer size) {
        return userRepository.findAllByAuthoritiesIn(Authority.ROLE_STUDENT, PageRequest.of(pageNum - 1, size));
    }

    public Page<User> listTeachers(Integer pageNum, Integer size) {
        return userRepository.findAllByAuthoritiesIn(Authority.ROLE_TEACHER, PageRequest.of(pageNum - 1, size));
    }


}
