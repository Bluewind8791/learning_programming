package com.sp.fc.web.controller;


import lombok.Data;
import lombok.Builder;
import lombok.NoArgsConstructor;

import java.util.List;

import lombok.AllArgsConstructor;


@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
public class UserSession {
    
    private String username;
    private List<SessionInfo> sessions;

    public int getCount() {
        return sessions.size();
    }
}
