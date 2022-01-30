package com.sp.fc.web.config;

import java.lang.reflect.Method;
import java.util.Collection;
import java.util.List;
import java.lang.annotation.Annotation;

import org.aopalliance.intercept.MethodInvocation;
import org.springframework.security.access.ConfigAttribute;
import org.springframework.security.access.SecurityConfig;
import org.springframework.security.access.annotation.SecuredAnnotationSecurityMetadataSource;
import org.springframework.security.access.method.MethodSecurityMetadataSource;
import org.springframework.security.access.prepost.PrePostAnnotationSecurityMetadataSource;
import org.springframework.core.annotation.AnnotationUtils;
import org.springframework.util.ClassUtils;



public class CustomMetadataSource implements MethodSecurityMetadataSource {

    PrePostAnnotationSecurityMetadataSource prePostAnnotationSecurityMetadataSource;
    SecuredAnnotationSecurityMetadataSource securedAnnotationSecurityMetadataSource;

    @Override
    public Collection<ConfigAttribute> getAttributes(Method method, Class<?> targetClass) {
        CustomSecurityTag annotation = findAnnotation(method, targetClass, CustomSecurityTag.class);

        if (annotation != null) {
            return List.of(new SecurityConfig(annotation.value()));
        }
        return null;
    }

    // 이 클래스는 method invocation 에 대하여 동작
    @Override
    public boolean supports(Class<?> clazz) {
        return MethodInvocation.class.isAssignableFrom(clazz);
    }

    private <A extends Annotation> A findAnnotation(Method method, Class<?> targetClass, Class<A> annotationClass) {
        Method specificMethod = ClassUtils.getMostSpecificMethod(method, targetClass);
        A annotation = AnnotationUtils.findAnnotation(specificMethod, annotationClass);
        if (annotation != null) {
            return annotation;
        }
        return annotation;
    }


    @Override
    public Collection<ConfigAttribute> getAttributes(Object object) throws IllegalArgumentException {
        return null;
    }

    @Override
    public Collection<ConfigAttribute> getAllConfigAttributes() {
        return null;
    }
}
