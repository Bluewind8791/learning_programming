package ch20;

class MyThread implements Runnable {

  @Override
  public void run() {
    
    int i;
    for (i=1; i<=200; i++) {
      System.out.print(i + "\t");
    }
  }
}

public class ThreadTest {
  
  public static void main(String[] args) {
    
    System.out.println(Thread.currentThread() + "start");

    // extends Thread
    // MyThread th1 = new MyThread();
    // MyThread th2 = new MyThread();

    // th1.start();
    // th2.start();
    
    // implements Runnable
    MyThread runnable = new MyThread();
    Thread th1 = new Thread(runnable);
    Thread th2 = new Thread(runnable);
    th1.start();
    th2.start();
    // Runnable 하면 스레드 2와 3이 번갈아가면서 호출됨.

    System.out.println(Thread.currentThread() + "end");

    // Runnable Interface
    Runnable run = new Runnable() {
      @Override
      public void run() {
        System.out.println("run");
      }
    };
    run.run();
  }
}
