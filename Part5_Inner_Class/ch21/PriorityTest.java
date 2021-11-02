package ch21;

class PriorityThread extends Thread {
  
  @Override
  public void run() {
    
    Thread t = Thread.currentThread();
    System.out.println(t + "start");
    
    
    int sum = 0;

    for (int i=0; i<=100000; i++) {
      sum += i;
    }

    System.out.println(t.getPriority() + "end");
  }
}

public class PriorityTest {

  public static void main(String[] args) {
    
    // int i;
    // for(i=Thread.MIN_PRIORITY; i<=Thread.MAX_PRIORITY; i++) {
      PriorityThread pt1 = new PriorityThread();
      PriorityThread pt2 = new PriorityThread();
      PriorityThread pt3 = new PriorityThread();

      pt1.setPriority(Thread.MIN_PRIORITY);
      pt1.setPriority(Thread.NORM_PRIORITY);
      pt3.setPriority(Thread.MAX_PRIORITY);

      pt1.start();
      pt2.start();
      pt3.start();
    // }
  }
}

