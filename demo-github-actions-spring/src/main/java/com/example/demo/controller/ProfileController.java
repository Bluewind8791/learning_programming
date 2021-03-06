package com.example.demo.controller;


import java.time.LocalDate;
import java.util.Arrays;
import java.util.List;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.core.env.Environment;

import lombok.RequiredArgsConstructor;


@RestController
@RequiredArgsConstructor
public class ProfileController {

    private final Environment env;

    // 실행중인 프로젝트의 Profile이 뭔지 확인할 수 있는 API
    @GetMapping("/profile")
    public String getProfile() {
        List<String> profile = Arrays.asList(env.getActiveProfiles());
        List<String> realProfiles = Arrays.asList("set1", "set2");
        String defaultProfile = profile.isEmpty() ? "default" : profile.get(0);

        return profile.stream()
                .filter(realProfiles::contains)
                .findAny()
                .orElse(defaultProfile);
    }

    @GetMapping({"", "/"})
    public String index() {
        String result = LocalDate.now().toString() + "오후 2시 27분";
        return result;
    }


}
