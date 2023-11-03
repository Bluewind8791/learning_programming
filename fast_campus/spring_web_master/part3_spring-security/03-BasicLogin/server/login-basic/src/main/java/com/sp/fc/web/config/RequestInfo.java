package com.sp.fc.web.config;

import lombok.Data;
import lombok.Builder;
import lombok.NoArgsConstructor;
import lombok.AllArgsConstructor;

import java.time.LocalDateTime;


/**
 * 인증객체 details 추가 파라미터 객체
 */
@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
public class RequestInfo {

    private String remoteIp;
    private String sessionId;
    private LocalDateTime loginTime;
}
