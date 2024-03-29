package com.sp.fc.web.config;

import org.aopalliance.intercept.MethodInvocation;
import org.springframework.security.access.AccessDecisionVoter;
import org.springframework.security.access.ConfigAttribute;
import org.springframework.security.core.Authentication;

import java.util.Collection;

/**
 * Custom voter
 */
public class CustomVoter implements AccessDecisionVoter<MethodInvocation> {

    private final String PREFIX = "SCHOOL_";

    @Override
    public boolean supports(ConfigAttribute attribute) {
        // 모든 조건에 참여
        return true;
//        return attribute.getAttribute().startsWith(PREFIX);
    }

    @Override
    public boolean supports(Class<?> clazz) {
        return MethodInvocation.class.isAssignableFrom(clazz);
    }

    @Override
    public int vote(Authentication authentication, MethodInvocation object, Collection<ConfigAttribute> attributes) {
        // 무조건 GRANTED
        return ACCESS_GRANTED;

//        String role = attributes.stream().filter(attr->attr.getAttribute().startsWith(PREFIX))
//                .map(attr->attr.getAttribute().substring(PREFIX.length()))
//                .findFirst().orElseGet(()->null);
//        if(role !=null && authentication.getAuthorities().stream().filter(auth->auth.getAuthority().equals("ROLE_"+role.toUpperCase()))
//        .findAny().isPresent()) {
//            return ACCESS_GRANTED;
//        }
//        return ACCESS_DENIED;
    }

}
