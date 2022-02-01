package com.sp.fc.web.config;

import java.util.Collection;

import org.aopalliance.intercept.MethodInvocation;
import org.springframework.security.access.AccessDecisionVoter;
import org.springframework.security.access.ConfigAttribute;
import org.springframework.security.core.Authentication;

public class CustomVoter implements AccessDecisionVoter<MethodInvocation> {

    private final String PREFIX = "SCHOOL_";

    @Override
    public boolean supports(ConfigAttribute attribute) {
        return attribute.getAttribute().startsWith(PREFIX); // "SCHOOL_" 로 시작하는 attribute 에는 참여
        // return true; // 어떤 조건이 와도 참여
    }

    @Override
    public boolean supports(Class<?> clazz) {
        return MethodInvocation.class.isAssignableFrom(clazz);
    }

    @Override
    public int vote(Authentication authentication, MethodInvocation object, Collection<ConfigAttribute> attributes) {

        // "SCHOOL_PRIMARY" 가 진입한다면 role 에는 PRIMARY 가 담긴다.
        String role = attributes.stream().filter(attr -> attr.getAttribute().startsWith(PREFIX))
            .map(attr -> attr.getAttribute().substring(PREFIX.length()))
            .findFirst().orElseGet(() -> null);

        

        // 만약 ROLE_ + PRIMARY 가 있다면 접근 허용
        if (role != null && authentication.getAuthorities().stream().filter(auth -> auth.getAuthority().equals("ROLE_"+ role.toUpperCase()))
        .findAny().isPresent()) {
            return ACCESS_GRANTED; // 
        }
        return ACCESS_DENIED;
    }
    
}
