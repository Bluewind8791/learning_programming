package ch01;


class OutClass {

  private int num = 10;
  private static int sNum = 20;

  private InClass inClass;

  public OutClass() {
    inClass = new InClass(); // Inner Class 생성
  }

  private class InClass {

    int iNum = 100;

    void inTest() {
      System.out.println("Outer Class의 Instance 변수 = " + num);
      System.out.println("Outer Class의 Static 변수 = " + sNum);
      System.out.println("Inner Class의 Instance 변수 = " + iNum);
    }
  }

  public void usingClass() {
    inClass.inTest(); // Inner Class 변수 사용하여 method 호출
  }


  /////////////////////////////////////////// Static Inner Class ///////////////////////////////////////////
  static class inStaticClass {

    int inNum = 100;
    static int sInNum = 200;

    // method
    void inTest() {
      // 외부 클래스의 인스턴스 변수 사용 불가
      System.out.println("내부 클래스의 Instance 변수 = " + inNum);
      System.out.println("내부 클래스의 Static 변수 = " + sInNum);
      System.out.println("외부 클래스의 Static 변수 = " + sNum);
    }

    static void sTest() {
      // Inner Class의 Instance 변수 사용 불가
      // Outer Class의 Instance 변수 사용 불가
      System.out.println("외부 클래스의 Static 변수 = " + sNum);
      System.out.println("내부 클래스의 Static 변수 = " + sInNum);
    }
  }
}



public class InnerTest {

  public static void main(String[] args) {

    // Instance Inner Class
    System.out.println("Using Instance Inner Class");
    OutClass outClass = new OutClass();
    outClass.usingClass();
    /*
    // InClass가 private가 아닐때 문법적으로는 이렇게 생성 가능
    OutClass.InClass inner = outClass.new InClass();
    inner.inTest();
    */

    // using Static Inner CLass
    System.out.println("\nUsing Static Inner Class");
    OutClass.inStaticClass sInClass = new OutClass.inStaticClass();
    sInClass.inTest();

    // 호출없이 바로 사용가능한 static method
    System.out.println("\nUsing Static Inner Class의 Static Method 호출");
    OutClass.inStaticClass.sTest();

  }
}
