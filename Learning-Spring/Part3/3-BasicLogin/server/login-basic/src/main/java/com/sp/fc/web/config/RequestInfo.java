package com.sp.fc.web.config;

import lombok.Data;
import lombok.Builder;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;

import lombok.AllArgsConstructor;


@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
public class RequestInfo {

    private String remoteIp;
    private String sessionId;
    private LocalDateTime loginTime;
}
