package com.sp.fc.site.manager.controller.vo;


import lombok.Data;
import lombok.Builder;
import lombok.NoArgsConstructor;
import lombok.AllArgsConstructor;


@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
public class TeacherData {

    private String schoolName;
    private Long userId;
    private String name;
    private String email;
    private long studentCount;

}
