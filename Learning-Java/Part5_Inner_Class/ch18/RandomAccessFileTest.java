package ch18;

import java.io.IOException;
import java.io.RandomAccessFile;

public class RandomAccessFileTest {
  
  public static void main(String[] args) throws IOException {
    
    RandomAccessFile rf = new RandomAccessFile("random.txt", "rw");
    
    rf.writeInt(100);
    System.out.println("File Pointer Location : " + rf.getFilePointer());

    rf.writeDouble(3.14);
    System.out.println("File Pointer Location : " + rf.getFilePointer());

    rf.writeUTF("Hello 안녕하세요");
    System.out.println("File Pointer Location : " + rf.getFilePointer());

    rf.seek(0);
    System.out.println("File Pointer Location : " + rf.getFilePointer());

    int i = rf.readInt();
    double d = rf.readDouble();
    String str = rf.readUTF();

    System.out.println("File Pointer Location : " + rf.getFilePointer());
    System.out.println(i);
    System.out.println(d);
    System.out.println(str);

    rf.close();
  }
}
