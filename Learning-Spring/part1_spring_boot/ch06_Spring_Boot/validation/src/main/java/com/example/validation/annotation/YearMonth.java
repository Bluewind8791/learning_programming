package com.example.validation.annotation;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

import javax.validation.Constraint;
import javax.validation.Payload;

import com.example.validation.validator.YearMonthValidator;


@Constraint(validatedBy = { YearMonthValidator.class }) // 이 클래스를 통하여 검사
@Target({ElementType.METHOD, ElementType.FIELD, ElementType.ANNOTATION_TYPE, ElementType.CONSTRUCTOR, ElementType.PARAMETER, ElementType.TYPE_USE})
@Retention(RetentionPolicy.RUNTIME)
public @interface YearMonth {
    
    String message() default "Please insert yyyyMM format!";

	Class<?>[] groups() default { };

	Class<? extends Payload>[] payload() default { };

    String pattern() default "yyyyMMdd";

}
