package ch10;

public class ManualCar extends Car {
  @Override
  public void drive() {
    System.out.println("Driver driving Car.");
  }

  @Override
  public void stop() {
    System.out.println("Driver stoped Car.");
  }
}
