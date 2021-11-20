package ch18;

import java.io.File;
import java.io.IOException;

public class FileTest {
  
  public static void main(String[] args) {
    
    File file = new File("C:\\Users\\castu\\projects\\Learning_Java\\Part5_Inner_Class\\newFile.txt");

    try {
      file.createNewFile();
    } catch (IOException e) {
      e.printStackTrace();
    }

    System.out.println(file.isFile());
    System.out.println(file.isDirectory());
    System.out.println(file.getName());
    System.out.println(file.getAbsolutePath());
    System.out.println(file.getPath());
    System.out.println(file.canRead());
    System.out.println(file.canWrite());

    file.delete();
  }
}
