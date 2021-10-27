package ch14;

import java.io.FileInputStream;
import java.io.IOException;


// 파일의 끝까지 한 바이트씩 자료 읽기
public class FileInputStreamTest2 {
  
  public static void main(String[] args) {
    
    int r;
    
    try (FileInputStream fis = new FileInputStream("input.txt")) {

      while ((r = fis.read()) != -1) {
        System.out.print((char)r);
      }

    } catch (IOException e) {
      System.out.println(e);
    }
  }
}
