package com.example.springioc;

// import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Component;


@Component
public class Encoder {
    
    private IEncoder iEncoder;

    //                      이 이름의 클래스를 할당함
    // public Encoder(@Qualifier("Base74Encoder") IEncoder iEncoder) {
    //     this.iEncoder = iEncoder;
    // }
    public Encoder(IEncoder iEncoder) {
        this.iEncoder = iEncoder;
    }

    public void setIEncoder(IEncoder iEncoder) {
        this.iEncoder = iEncoder;
    }

    public String encode(String message) {
        return iEncoder.encode(message);
    }
}
