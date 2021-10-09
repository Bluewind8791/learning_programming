package ch09;


public class TestComputer {
  public static void main(String[] args) {
    
    // Desktop desktop = new Desktop();
    Computer desktop = new Desktop(); // 이렇게도 가능 (상위 클래스)
    desktop.turnOn();
    desktop.display();
    desktop.typing();
    desktop.turnOff();
  }
}
