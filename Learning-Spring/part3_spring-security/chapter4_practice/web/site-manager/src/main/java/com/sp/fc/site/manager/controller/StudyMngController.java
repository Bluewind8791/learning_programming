package com.sp.fc.site.manager.controller;

import com.sp.fc.user.service.UserService;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import lombok.RequiredArgsConstructor;

@Controller
@RequiredArgsConstructor
@RequestMapping("/manager/study")
public class StudyMngController {

    private final UserService userService;

    @GetMapping("/list")
    public String list(
        @RequestParam(value = "pageNum", defaultValue = "1") Integer pageNum,
        @RequestParam(value = "size", defaultValue = "10") Integer size,
        Model model
    ) {
        model.addAttribute("menu", "study");
        return "manager/study/list.html";
    }


}
