package com.sp.fc.web.controller;

import java.util.List;

import com.sp.fc.web.student.Student;
import com.sp.fc.web.student.StudentManager;
import com.sp.fc.web.teacher.Teacher;

import lombok.RequiredArgsConstructor;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.prepost.PreAuthorize;
import org.springframework.security.core.annotation.AuthenticationPrincipal;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequiredArgsConstructor
@RequestMapping("/api/teacher")
public class MobTeacherController {
    
    private final StudentManager studentManager;

    @PreAuthorize("hasAnyAuthority('ROLE_TEACHER')")
    @GetMapping("/students")
    public List<Student> students(@AuthenticationPrincipal Teacher teacher){
        return studentManager.myStudentList(teacher.getId());
    }
}
