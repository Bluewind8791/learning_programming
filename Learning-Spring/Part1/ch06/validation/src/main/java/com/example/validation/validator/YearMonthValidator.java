package com.example.validation.validator;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

import javax.validation.ConstraintValidator;
import javax.validation.ConstraintValidatorContext;

import com.example.validation.annotation.YearMonth;


public class YearMonthValidator implements ConstraintValidator<YearMonth, String> {

    private String pattern;
    

    @Override
    public void initialize(YearMonth constraintAnnotation) {
        this.pattern = constraintAnnotation.pattern();
    }

    @Override
    public boolean isValid(String value, ConstraintValidatorContext context) {

        System.out.println("isValid is working");

        // yyyyMM
        try { // default가 yyyyMMdd이기때문에 뒤에 01을 붙임
            LocalDate localDate = LocalDate.parse(value+"01", DateTimeFormatter.ofPattern(this.pattern));
        } catch (Exception e) {
            return false;
        }

        return true;
    }

}
