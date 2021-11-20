package ch05;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;

public class ArrayListStreamTest {
  public static void main(String[] args) {
    
    List<String> sList = new ArrayList<String>();
    sList.add("Tomas");
    sList.add("Edward");
    sList.add("Jack");

    // 
    Stream<String> stream = sList.stream();
    stream.forEach(s -> System.out.println(s));

    System.out.println("\n== sorted를 이용하여 정렬하여 출력 ==");
    sList.stream().sorted().forEach(s -> System.out.print(s + "\t"));

    System.out.println("\n\n== map을 이용하여 문자열의 길이를 나타내기 ==");
    sList.stream().map(mapper -> mapper.length()).forEach(n -> System.out.print(n + "\t"));

    System.out.println("\n\n== filter를 사용하여 문자열 길이가 5이상만 출력 ==");
    sList.stream().filter(s -> s.length() >= 5).forEach(str -> System.out.print(str + "\t"));
  }
}
