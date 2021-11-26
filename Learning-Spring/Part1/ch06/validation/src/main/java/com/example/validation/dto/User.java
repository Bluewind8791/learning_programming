package com.example.validation.dto;

// import java.time.LocalDate;
// import java.time.format.DateTimeFormatter;

// import javax.validation.constraints.AssertTrue;
import javax.validation.constraints.Email;
import javax.validation.constraints.Max;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;
// import javax.validation.constraints.Size;

import com.example.validation.annotation.YearMonth;


public class User {

    @NotBlank
    private String name;

    @Max(value = 90, message = "Age <= 90")
    private int age;

    @Email // e-mail 형식으로 확인
    private String email;

    @Pattern(regexp = "^\\d{2,3}-\\d{3,4}-\\d{4}$", message = "It does not match the form of the cell phone number.") // 정규식
    private String phoneNumber;

    @YearMonth
    private String reqYearMonth; // yyyyMM

    // @AssertTrue(message = "Please insert YYYYMM form") // boolean에는 is-- 로 메소드명 지정
    // public boolean isReqYearMonthValidation() {
    //     // this.reqYearMonth = getReqYearMonth() + "01";
    //     return true;
    // }


    // getter and setter
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public int getAge() {
        return age;
    }
    public String getEmail() {
        return email;
    }
    public String getPhoneNumber() {
        return phoneNumber;
    }
    public void setAge(int age) {
        this.age = age;
    }
    public void setEmail(String email) {
        this.email = email;
    }
    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }
    public String getReqYearMonth() {
        return reqYearMonth;
    }
    public void setReqYearMonth(String reqYearMonth) {
        this.reqYearMonth = reqYearMonth;
    }


    @Override
    public String toString() {
        return "name=" +name+ ", age=" +age+ ", email=" +email+ ", phone number=" +phoneNumber+ ", Year Month=" +reqYearMonth;
    }
}
