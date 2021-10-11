package ch15;

public class TestBookShelf {
  public static void main(String[] args) {
    
    Queue bookQueue = new BookShelf();
    bookQueue.enQueue("토지1");
    bookQueue.enQueue("토지2");
    bookQueue.enQueue("토지3");
    bookQueue.enQueue("토지4");
    bookQueue.enQueue("토지5");

    System.out.println(bookQueue.getSize());
    System.out.println(bookQueue.deQueue()); // 들어간 순서대로 앞부터 꺼내기
    System.out.println(bookQueue.deQueue());
    System.out.println(bookQueue.deQueue());
    System.out.println(bookQueue.deQueue());
    System.out.println(bookQueue.deQueue());
  }
}
