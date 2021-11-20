package ch16;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
// import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
// import java.io.InputStreamReader;
// import java.net.Socket;

public class FileCopyTest {
  
  public static void main(String[] args) {
    
    long milliSecond = 0;

    try(BufferedInputStream bis = new BufferedInputStream(new FileInputStream("a.zip")); 
    BufferedOutputStream bos = new BufferedOutputStream(new FileOutputStream("copy.zip"))) {
      
      milliSecond = System.currentTimeMillis(); // start counting

      int i;
      while((i=bis.read()) != -1) {
        bos.write(i);
      }

      milliSecond = System.currentTimeMillis() - milliSecond; // end of counting
      
    } catch (IOException e) {
      System.out.println(e);
    }

    System.out.println("Program shutdown.\nThe program takes " + milliSecond);

    // // Socket
    // Socket socket = new Socket();
    // BufferedReader br;
    // try {
    //   br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
    //   br.readLine();
    // } catch (IOException e) {
    //   e.printStackTrace();
    // }
    

  }
}
