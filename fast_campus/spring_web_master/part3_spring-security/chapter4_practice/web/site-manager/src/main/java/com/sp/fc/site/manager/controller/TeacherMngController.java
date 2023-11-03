package com.sp.fc.site.manager.controller;

import com.sp.fc.site.manager.controller.vo.TeacherData;
import com.sp.fc.user.service.UserService;

import org.springframework.data.domain.Page;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import lombok.RequiredArgsConstructor;

@Controller
@RequiredArgsConstructor
@RequestMapping("/manager/teacher")
public class TeacherMngController {

    private final UserService userService;

    @GetMapping("/list")
    public String list(
        @RequestParam(value = "pageNum", defaultValue = "1") Integer pageNum,
        @RequestParam(value = "size", defaultValue = "10") Integer size,
        Model model
    ) {
        model.addAttribute("menu", "teacher");
        Page<TeacherData> teacherList = userService.listTeachers(pageNum, size).map(t -> 
            new TeacherData(t.getSchool().getName(), t.getUserId(), t.getName(), t.getEmail(), 0L)
        );
        teacherList.getContent().stream().forEach(data -> {
            data.setStudentCount(userService.findTeacherStudentCount(data.getUserId()));
        });
        model.addAttribute("page", teacherList);
        return "manager/teacher/list.html";
    }
}
