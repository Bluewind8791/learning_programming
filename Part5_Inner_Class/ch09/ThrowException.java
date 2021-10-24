package ch09;

import java.io.FileInputStream;
import java.io.FileNotFoundException;


public class ThrowException {
  
  public Class loadClass(String fileName, String className) throws FileNotFoundException, ClassNotFoundException {

    FileInputStream fis = new FileInputStream(fileName);
    Class c = Class.forName(className);
    return c;
  }


  public static void main(String[] args) {
    
    ThrowException test = new ThrowException();

    // try {
    //   test.loadClass("a.txt", "abc");
    // } catch (FileNotFoundException e) {
    //   System.out.println(e);
    // } catch (ClassNotFoundException e) {
    //   System.out.println(e);
    // }

    try {
      test.loadClass("a.txt", "java.lang.String");
    } catch (FileNotFoundException | ClassNotFoundException e) {
      System.out.println(e);
    } catch (Exception e) {
      // default exception... 나머지 모든 예외를 여기서 처리
      // 예외의 가장 윗 개념이기 때문에 상위에 쓰면 안됨.
    }

    System.out.println("End of Main Function");
  }

}
