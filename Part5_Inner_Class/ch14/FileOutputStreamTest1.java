package ch14;

import java.io.FileOutputStream;
import java.io.IOException;

// 파일에서 한 바이트씩 자료 읽기

public class FileOutputStreamTest1 {
  
  public static void main(String[] args) {
    
    try (FileOutputStream fos = new FileOutputStream("output.txt")) {
      
      fos.write(65);
      fos.write(66);
      fos.write(67);

    } catch (IOException e) {
      System.out.println(e);
    }

    System.out.println("End of Program.");
  }
}
