package ch15;

import java.io.FileWriter;
import java.io.IOException;

public class FileWriterTest {
  
  public static void main(String[] args) {
    
    try (FileWriter fw = new FileWriter("reader.txt")) {
  
      fw.write('A'); // 문자 하나 쓰기

      char buf[] = {'B','U','F','F','E','R'};
      fw.write(buf); // 문자 배열 쓰기

      fw.write("한글 쓰기");

      fw.write(buf, 1, 2); // 버퍼에 부분 쓰기
      fw.write("65"); // 숫자 그대로 쓰기
  
    } catch (IOException e) {
      System.out.println(e);
    }

    System.out.print("\nEnd of System.");
  }

}
