package com.sp.fc.web.teacher;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.security.core.GrantedAuthority;

import java.util.List;
import java.util.Set;

import com.sp.fc.web.student.Student;

@Data
@AllArgsConstructor
@NoArgsConstructor
@Builder
public class Teacher {

    private String id;
    private String username;
    private Set<GrantedAuthority> role;

    private List<Student> studentList; // 선생님이 학생 리스트를 가지고 있다.

}
