package ch09;

// Notebook에서 구현하지 않은 나머지 한개의 추상 메서드를 구현하여 abstract 안붙임.
public class MyNotebook extends Notebook{
  
  @Override
  public void typing() {
    System.out.println("Labtop Keyboard Typing");
  }
}
