package com.sp.fc.web.controller;

import com.sp.fc.web.service.SecurityMessageService;

import org.springframework.security.access.intercept.aopalliance.MethodSecurityInterceptor;
import org.springframework.security.access.prepost.PreAuthorize;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HomeController {

    MethodSecurityInterceptor methodSecurityInterceptor;
    
    private final SecurityMessageService securityMessageService;

    public HomeController(SecurityMessageService securityMessageService) {
        this.securityMessageService = securityMessageService;
    }

    @PreAuthorize("hasRole('USER')")
    @GetMapping("/greeting")
    public String greeting() {
        return "hello";
    }

    // @PreAuthorize("hasRole('USER')")
    // @PostMapping("/greeting/{name}")
    // public String greeting(@PathVariable String name) {
    //     return "hello " + securityMessageService.message(name);
    // }

    @PreAuthorize("@nameCheck.check(#name)")
    @GetMapping("/greeting/{name}")
    public String greeting(@PathVariable String name) {
        return "hello " + securityMessageService.message(name);
    }

}
