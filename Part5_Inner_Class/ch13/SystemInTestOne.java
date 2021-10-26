package ch13;

import java.io.IOException;
import java.io.InputStreamReader;

public class SystemInTestOne {
  
  public static void main(String[] args) {
    
    System.out.println("Input Korean and Press [ENTER]");
    int i;
    int k;

    // InputStreamReader를 통하여 한국어 읽기
    try {
      InputStreamReader isr = new InputStreamReader(System.in);
      while ((k = isr.read()) != '\n') {
        // System.out.print(i);
        System.out.print((char)k);
      }
    } catch (IOException e) {
      e.printStackTrace();
    }


    System.out.println("알파벳을 여러개를 쓰고 [ENTER]를 누르세요.");

    // System read --return--> int
    // 1 byte 씩 읽음
    try {
      while ((i = System.in.read()) != '\n') {
        // System.out.print(i);
        System.out.print((char)i);
      }
    } catch (IOException e) {
      e.printStackTrace();
    }




  }
}
