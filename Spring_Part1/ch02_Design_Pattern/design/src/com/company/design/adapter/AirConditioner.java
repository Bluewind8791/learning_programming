package com.company.design.adapter;

public class AirConditioner implements Electronic220V {

  @Override
  public void connect() {
    System.out.println("Air Conditioner Connected. (220V)");
  }
  

}
