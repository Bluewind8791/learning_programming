package com.example.object_mapper.dto;

import java.util.List;

public class User {
    
    private String name;
    private int age;
    private List<Car> cars;


    public List<Car> getCars() {
        return cars;
    }
    public void setCars(List<Car> cars) {
        this.cars = cars;
    }

    public int getAge() {
        return age;
    }
    public String getName() {
        return name;
    }
    public void setAge(int age) {
        this.age = age;
    }
    public void setName(String name) {
        this.name = name;
    }
    @Override
    public String toString() {
        return "name=" + name + ", age=" + age+ ", car list=" +cars;
    }
}
