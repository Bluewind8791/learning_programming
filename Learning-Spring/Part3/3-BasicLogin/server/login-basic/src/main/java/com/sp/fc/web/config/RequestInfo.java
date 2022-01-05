package com.sp.fc.web.config;

import lombok.Data;
import lombok.Builder;
import lombok.NoArgsConstructor;
import lombok.AllArgsConstructor;

import java.time.LocalDateTime;


@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
public class RequestInfo {

    private String remoteIp;
    private String sessionId;
    private LocalDateTime loginTime;
}
