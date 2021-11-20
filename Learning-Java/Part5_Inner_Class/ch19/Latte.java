package ch19;

public class Latte extends Decorator {

  // constructor
  public Latte(Coffee coffee) {
    super(coffee);
  }

  @Override
  public void brewing() {
    super.brewing();
    System.out.print("and Add Milk. ");
  }
  
}
