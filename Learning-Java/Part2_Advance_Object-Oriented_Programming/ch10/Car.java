package ch10;

public abstract class Car {
  
  public abstract void drive();
  public abstract void stop();

  public void startCar() {
    System.out.println("Car start Engine.");
  }

  public void turnOff() {
    System.out.println("Turn off the Engine.");
  }

  // 재정의 불가
  final public void run() {
    startCar();
    drive();
    stop();
    turnOff();
  }

}
