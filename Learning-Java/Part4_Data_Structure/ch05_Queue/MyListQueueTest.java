package ch05_Queue;

public class MyListQueueTest {
  public static void main(String[] args) {
    
    MyLinkedQueue listQueue = new MyLinkedQueue();
    listQueue.enQueue("A");
    listQueue.enQueue("B");
    listQueue.enQueue("C");

    listQueue.printQueue();

    System.out.println(listQueue.deQueue()); // A 먼저 들어간게 먼저 꺼내짐
    System.out.println(listQueue.deQueue());
    
  }
}
