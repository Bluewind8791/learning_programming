package com.sp.fc.site.study.controller.vo;


import lombok.Data;
import lombok.Builder;
import lombok.NoArgsConstructor;
import lombok.AllArgsConstructor;


@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
public class StudySignUpForm {

    private Long schoolId;
    private Long teacherId;
    private String name;
    private String email;
    private String password;
    private String rePassword;
    private String grade;

}
