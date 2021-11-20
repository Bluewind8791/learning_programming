package ch15;

public class Customer implements Buy, Sell {

  @Override
  public void sell() {
    System.out.println("Customer is Selling");
    
  }

  @Override
  public void buy() {
    System.out.println("Customer is Buying");
  }
  
  @Override
  public void order() {
    System.out.println("Customer is Ordering");
  }

  public void hello() {
    System.out.println("Customer says hello");
  }
}
