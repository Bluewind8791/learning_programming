package ch14;

public class TestCalc {
  public static void main(String[] args) {
    Calc calc = new CompleteCalc();

    int num1 = 20;
    int num2 = 5;

    System.out.println(calc.add(num1, num2));
    System.out.println(calc.minus(num1, num2));
    System.out.println(calc.divide(num1, num2));
    System.out.println(calc.times(num1, num2));

    // default method
    calc.description();

    // static method : new 하지않고도 바로 사용가능
    int[] arr = {1,2,3,4,5};
    int sum = Calc.total(arr);
    System.out.println(sum);
  }
}
