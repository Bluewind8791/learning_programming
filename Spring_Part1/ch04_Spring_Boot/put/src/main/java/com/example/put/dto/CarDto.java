package com.example.put.dto;

import com.fasterxml.jackson.annotation.JsonProperty;

public class CarDto {
  
  private String name;
  @JsonProperty("car_number")
  private String carNumber;

  public String getCarNum() {
    return carNumber;
  }
  public String getName() {
    return name;
  }
  public void setCarNum(String carNumber) {
    this.carNumber = carNumber;
  }
  public void setName(String name) {
    this.name = name;
  }

  @Override
  public String toString() {
    return "Car name : "+name+" / Car number : "+carNumber;
  }
}
