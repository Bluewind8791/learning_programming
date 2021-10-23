package ch02;

public class addTest {
  
  public static void main(String[] args) {
    
    // lambda
    // Add add = (x, y) -> {return x + y;};
    Add add = (x, y) -> x + y;


    // call
    System.out.println(add.add(2, 3));

  }
}
