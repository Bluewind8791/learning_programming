package com.example.objectmapper;

import com.fasterxml.jackson.annotation.JsonProperty;

public class User {
    private String name;
    private int age;
    
    @JsonProperty("phone_number")
    private String phoneNumber;


    // default 생성자
    public User() {
        this.name = null;
        this.age = 0;
        this.phoneNumber = null;
    }

    public User(String name, int age, String phoneNumber) {
        this.name = name;
        this.age = age;
        this.phoneNumber = phoneNumber;
    }

    
    public String getPhoneNumber() {
        return phoneNumber;
    }
    public int getAge() {
        return age;
    }
    public String getName() {
        return name;
    }


    @Override
    public String toString() {
        return "name = " +name+ ", age = " +age+ ", phone number = " +phoneNumber;
    }
}
