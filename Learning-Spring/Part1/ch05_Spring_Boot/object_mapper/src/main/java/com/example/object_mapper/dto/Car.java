package com.example.object_mapper.dto;

import com.fasterxml.jackson.annotation.JsonProperty;

public class Car {
    
    private String name;

    @JsonProperty("car_number")
    private String carNumber;

    @JsonProperty("TYPE")
    private String type;


    public String getCarNumber() {
        return carNumber;
    }
    public String getName() {
        return name;
    }
    public String getType() {
        return type;
    }
    public void setCarNumber(String carNumber) {
        this.carNumber = carNumber;
    }
    public void setName(String name) {
        this.name = name;
    }
    public void setType(String type) {
        this.type = type;
    }

    @Override
    public String toString() {
        return "Car name=" +name+ ", car number=" +carNumber+ ", type=" +type;
    }
}
