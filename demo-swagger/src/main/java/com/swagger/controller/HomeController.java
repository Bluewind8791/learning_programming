package com.swagger.controller;

import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.servlet.ModelAndView;

import lombok.RequiredArgsConstructor;

@RestController
@RequiredArgsConstructor
public class HomeController {

    @GetMapping({"/",""})
    public ModelAndView home() {
        return new ModelAndView("home", HttpStatus.OK);
    }

}
