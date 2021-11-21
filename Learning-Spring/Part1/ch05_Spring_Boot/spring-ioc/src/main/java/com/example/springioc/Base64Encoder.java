package com.example.springioc;

import java.util.Base64;

import org.springframework.stereotype.Component;


// component에 이름을 지어줄 수 있음
@Component("Base74Encoder")
public class Base64Encoder implements IEncoder {
    
    @Override
    public String encode(String message) {

        return Base64.getEncoder().encodeToString(message.getBytes());
    }
}
