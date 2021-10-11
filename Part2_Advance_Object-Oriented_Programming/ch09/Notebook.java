package ch09;

// 구현을 하나라도 안하면 abstract 붙여야 함.
public abstract class Notebook extends Computer{
  
  @Override
  public void display() {
    System.out.println("Notebook Displaying.");
  }
}
