package ch01;

// -- Local Inner Class --
class Outer2 {

  int outNum = 100; // Outer Instance Variable
  static int sNum = 200; // Outer Static Variable

  /*
  // runnable : class를 thread화 시킬때 사용
  // getRunnable method 안에 class가 있기때문에 Local Inner Class가 된다.
  Runnable getRunnable(final int i) {

    // int i and num 은 stack memory에 생성됨.
    // final로 선언시 상수화 되어 상수 메모리에 잡혀서 method가 끝나도 사라지지 않음.
    // 그래서 변경 불가능하며 자동으로 컴파일러가 final 선언함.
    final int num = 10; // local variable

    class MyRunnable implements Runnable {

      int localNum = 20;

      @Override
      public void run() {
        
        // i = 100;  // 가져다 쓸때는 오류가 안나지만 변경시 오류남
        // num = 20; // final로 컴파일러가 자동 선언하기때문에 변경 불가능

        System.out.println("i = " + i);
        System.out.println("num = " + num);
        System.out.println("Local Num = " + localNum);

        System.out.println("외부 클래스 인스턴스 변수 : outNum = " + outNum);
        System.out.println("외부 클래스 정적 변수 : sNum = " + Outer2.sNum);
      }
    }
    return new MyRunnable();
  }
*/


  // -- Anonymous Inner Class --
  Runnable getRunnable(int i) {
    int num = 10;

    return new Runnable() { // 클래스 없이 바로 return
      int localNum = 20;

      @Override
      public void run() {
        System.out.println("i = " + i);
        System.out.println("num = " + num);
        System.out.println("Local Num = " + localNum);
        System.out.println("외부 클래스 인스턴스 변수 : outNum = " + outNum);
        System.out.println("외부 클래스 정적 변수 : sNum = " + Outer2.sNum);
      }
    };
  }
    // Anonymous
    Runnable runnable = new Runnable() {
      @Override
      public void run() {
        System.out.println("Anonymous Runnable Class is called.");
      };
    };

}

public class AnonymousInnerTest {
  public static void main(String[] args) {
    
    Outer2 out = new Outer2();
    Runnable runner = out.getRunnable(100);

    runner.run();

    // 익명 내부 클래스 호출
    System.out.println("\nCall Anonymous Class");
    out.runnable.run();
  }
}

