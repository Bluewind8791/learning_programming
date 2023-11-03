package com.sp.fc.site.controller.vo;


import lombok.Data;
import lombok.Builder;
import lombok.NoArgsConstructor;
import lombok.AllArgsConstructor;


@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
public class TeacherSignUpForm {
    
    private Long schoolId;
    private String name;
    private String email;
    private String password;
    private String rePassword;
    
}
