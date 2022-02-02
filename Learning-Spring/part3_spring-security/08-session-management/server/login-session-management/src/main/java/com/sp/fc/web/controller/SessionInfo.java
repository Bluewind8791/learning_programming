package com.sp.fc.web.controller;

import lombok.Data;
import lombok.Builder;
import lombok.NoArgsConstructor;

import java.util.Date;

import lombok.AllArgsConstructor;


@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
public class SessionInfo {
    
    private String sessionId;
    private Date time;
}
