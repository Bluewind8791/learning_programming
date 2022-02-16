package com.sp.fc.site.study.controller.vo;


import lombok.Data;
import lombok.Builder;
import lombok.NoArgsConstructor;
import lombok.AllArgsConstructor;


@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
public class Answer {
    
    private Long paperId;
    private Long problemId;
    private Integer indexNum;
    private String answer;

}
