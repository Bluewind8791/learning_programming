package com.sp.fc.web.service;

import org.springframework.security.access.prepost.PreAuthorize;
import org.springframework.stereotype.Service;

@Service
public class SecurityMessageService {


    @PreAuthorize("hasRole('USER')")
    public String message(String name){
        return name;
    }

}
