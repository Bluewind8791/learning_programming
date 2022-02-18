package com.sp.fc.site.controller;

import com.sp.fc.site.controller.vo.TeacherSignUpForm;
import com.sp.fc.user.domain.Authority;
import com.sp.fc.user.domain.User;
import com.sp.fc.user.service.SchoolService;
import com.sp.fc.user.service.UserService;

import org.springframework.http.MediaType;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;

import lombok.RequiredArgsConstructor;


@Controller
@RequiredArgsConstructor
public class TeacherSignupController {
    
    private final SchoolService schoolService;
    private final UserService userService;

    @GetMapping("/")
    public String signUp(Model model) {
        model.addAttribute("site", "study");
        model.addAttribute("cityList", schoolService.cities());
        return "/teacher/signup";
    }

    @PostMapping(value = "/signup/teacher", consumes = {"application/x-www-form-urlencoded;charset=UTF-8", MediaType.APPLICATION_FORM_URLENCODED_VALUE})
    public String signup(TeacherSignUpForm form, Model model) {
        final User teacher = User.builder()
                                .name(form.getName())
                                .email(form.getEmail())
                                .password(form.getPassword())
                                .enabled(true)
                                .build();
        schoolService.findSchool(form.getSchoolId()).ifPresent(school -> teacher.setSchool(school));
        User savedUser = userService.save(teacher);
        userService.addAuthority(savedUser.getUserId(), Authority.ROLE_TEACHER);
        model.addAttribute("site", "teacher");
        return "loginForm.html";
    }

}
