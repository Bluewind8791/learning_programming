package ch09;

// abstract = 추상
public abstract class Computer {
  
  // 이 클래스에서 구현하지 못할 메서드는 선언만 해놓고 하위 클래스에게 정의하는 것은 위임
  public abstract void display();
  public abstract void typing();

  public void turnOn() {
    System.out.println("Turn on");
  }

  public void turnOff() {
    System.out.println("Turn off");
  }
}
