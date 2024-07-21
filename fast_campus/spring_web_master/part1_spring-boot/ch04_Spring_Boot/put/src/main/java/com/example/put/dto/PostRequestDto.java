package com.example.put.dto;

import java.util.List;

import com.fasterxml.jackson.databind.PropertyNamingStrategy;
import com.fasterxml.jackson.databind.annotation.JsonNaming;

@JsonNaming(value = PropertyNamingStrategy.SnakeCaseStrategy.class)
public class PostRequestDto {
  
  private String name;
  private int age;
  private List<CarDto> carList;

  public int getAge() {
    return age;
  }
  public List<CarDto> getCarList() {
    return carList;
  }
  public String getName() {
    return name;
  }
  public void setAge(int age) {
    this.age = age;
  }
  public void setCarList(List<CarDto> carList) {
    this.carList = carList;
  }
  public void setName(String name) {
    this.name = name;
  }

  @Override
  public String toString() {
    return "[PostRequestDto]\nname="+name+" / age="+age+" / carList"+carList;
  }
}
