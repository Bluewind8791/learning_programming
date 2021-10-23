package ch04;

import java.util.Arrays;
import java.util.stream.IntStream;

public class IntArrayStreamTest {
  public static void main(String[] args) {
    
    int[] arr = {1,2,3,4,5};

    // == normal ==
    // for (int num : arr) {
    //   System.out.print(num+ " ");
    // }

    // == Stream ==
    // Arrays.stream(arr); // return IntStream
    Arrays.stream(arr).forEach(n -> System.out.print(n + " ")); // insert action

    IntStream iStream = Arrays.stream(arr);
    iStream.forEach(n -> System.out.print(n + " "));

    int sum = Arrays.stream(arr).sum();
    System.out.println(sum);
  }
}
