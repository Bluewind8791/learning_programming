package ch09;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public class FileExceptionHandling {
  
  public static void main(String[] args) {
    
    /*
    // --- try-catch ---
    FileInputStream fis = null;
    try {
      // open the file
      fis = new FileInputStream("a.txt");

    } catch (FileNotFoundException e) {
      // if failed, print
      System.out.println(e);
      // e.printStackTrace();

    } finally {
      if (fis != null) {
        try {
          fis.close();
        } catch (IOException e) {
          System.out.println(e);
        }
      }
      System.out.println("Finally");
    }
    */

    // --- try-with-resources ---
    try (FileInputStream fis = new FileInputStream("a.txt")) {
      System.out.println("Reading a.txt file.");

    } catch (FileNotFoundException e) {
      System.out.println(e);
    } catch (IOException e) {
      System.out.println(e);
    }


    System.out.println("--- End of main function ---");
  }
}
