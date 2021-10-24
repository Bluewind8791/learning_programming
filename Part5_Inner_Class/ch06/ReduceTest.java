package ch06;

import java.util.Arrays;
import java.util.function.BinaryOperator;


class CompareString implements BinaryOperator<String> {

  @Override
  public String apply(String str1, String str2) {
    if (str1.getBytes().length >= str2.getBytes().length) 
      return str1;
    else return str2;
  }
}


public class ReduceTest {
  
  public static void main(String[] args) {
    
    // lambda expression
    String greeting[] = {"안녕하세요", "Hello", "Bonjur", "Ni Hao"};

    //                           초기값
    System.out.println(Arrays.stream(greeting).reduce("", (str1, str2) -> 
    {if (str1.getBytes().length >= str2.getBytes().length) 
      return str1;
    else return str2;}
    ));

    // BinaryOperator을 이용하여 사용하기
    String print = Arrays.stream(greeting).reduce(new CompareString()).get();
    System.out.println(print);


  }
}
