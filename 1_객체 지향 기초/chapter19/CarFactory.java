package chapter19;

// singleton pattern
public class CarFactory {

  private static CarFactory instance = new CarFactory();

  private CarFactory() {}

  public static CarFactory getInstance() {
    if (instance == null) {
      instance = new CarFactory();
    }
    return instance;
  }

  public Car createCar() {
    Car car = new Car();
    return car;
  }
  
}

/*
자동차 공장이 있습니다. 자동차 공장은 유일한 객체이고
이 공장에서 생산되는 자동차는 제작될 때 마다 고유의 번호가 부여됩니다.
자동차 번호가 10001부터 시작되어 생산될 때마다 1씩 증가하여 번호가 붙도록
자동차 공장 클래스, 자동차 클래스를 구현하세요.
*/

