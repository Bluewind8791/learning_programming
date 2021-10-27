package ch14;

import java.io.FileInputStream;
import java.io.IOException;


// 파일에서 바이트 배열로 자료 읽기 ( 배열에 남아 있는 자료가 있을 수 있음에 유의 )
public class FileInputStreamTest3 {
  
  public static void main(String[] args) {
    
    int r;
    
    try (FileInputStream fis = new FileInputStream("input2.txt")) {

      byte[] bs = new byte[10];

      while ((r = fis.read(bs, 1, 9)) != -1) {

        for (int j=0; j<r; j++) {
          System.out.print((char)bs[j] + " ");
        }
        System.out.println(" : read " + r + " byte");
      }

    } catch (IOException e) {
      System.out.println(e);
    }

    // A B C D E F G H I J  : read 10 byte
    // K L M N O P Q R S T  : read 10 byte
    // U V W X Y Z  : read 6 byte



    System.out.println("Program shutdown...");
  }
}
