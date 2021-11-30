package com.example.filter.dto;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;


// @Getter, @Setter - get set method 대신 lombok 활용
@Data                   // getter, setter, toString, hashCode, canEqual 다 만들어줌
@NoArgsConstructor      // 파라미터가 없는 기본 생성자를 만들어줌 User()
@AllArgsConstructor     // 모든 필드의 값을 파라미터로 받는 생성자 User(String, int)
public class User {
    
    private String name;
    private int age;


}
