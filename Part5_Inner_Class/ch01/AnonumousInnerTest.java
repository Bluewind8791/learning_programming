package ch01;

// -- Local Inner Class --
class Outer2 {
  
  // runnable : class를 thread화 시킬때 사용
  Runnable getRunnable() {

    class MyRunnable implements Runnable {

      @Override
      public void run() {
        // TODO Auto-generated method stub
        
      }

    }

    return new MyRunnable();
  }


}


public class AnonumousInnerTest {
  public static void main(String[] args) {
    
  }
}
