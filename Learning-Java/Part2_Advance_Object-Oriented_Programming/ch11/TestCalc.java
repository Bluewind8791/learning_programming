package ch11;

public class TestCalc {
  public static void main(String[] args) {
    Calc calc = new CompleteCalc();

    int num1 = 20;
    int num2 = 5;

    System.out.println(calc.add(num1, num2));
    System.out.println(calc.minus(num1, num2));
    System.out.println(calc.divide(num1, num2));
    System.out.println(calc.times(num1, num2));

    
  }
}
