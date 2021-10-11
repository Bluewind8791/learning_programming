package ch09;

// Computer의 추상 메서드를 구현할꺼면 구현하고 아니면 abstract를 붙여야 한다.
public class Desktop extends Computer {

  @Override
  public void display() {
    System.out.println("Desktop Display");
  }
  
  @Override
  public void typing() {
    System.out.println("Keyboard Typing");
  }

  @Override
  public void turnOff() {
    System.out.println("Desktop Turn Off");
  }
}
