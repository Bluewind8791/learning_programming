package com.sp.fc.site.manager.controller.vo;


import lombok.Data;
import lombok.Builder;
import lombok.NoArgsConstructor;
import lombok.AllArgsConstructor;


@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
public class StudyData {
    
    private String schoolName;
    private Long userId;
    private String name;
    private String email;
    private String grade;

}
