package com.sp.fc.site.teacher.controller.vo;


import lombok.Data;
import lombok.Builder;
import lombok.NoArgsConstructor;
import lombok.AllArgsConstructor;


@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
public class ProblemInput {

    private Long paperTemplateId;
    private Long problemId;
    private String content;
    private String answer;

}
