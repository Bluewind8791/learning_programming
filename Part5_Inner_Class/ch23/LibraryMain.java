package ch23;

import java.util.ArrayList;


class Library {

  public ArrayList<String> shelf = new ArrayList<>();

  public Library() {
    shelf.add("DUNE1");
    shelf.add("DUNE2");
    shelf.add("DUNE3");
    // shelf.add("DUNE4");
    // shelf.add("DUNE5");
    // shelf.add("DUNE6");
  }


  public synchronized String rentalBook() throws InterruptedException {

    Thread t = Thread.currentThread();

    // no resource
    while (shelf.size() == 0) {
      System.out.println(t.getName() + " is waiting.");
      wait();
      System.out.println(t.getName() + " waiting end.");
    }

    if (shelf.size() > 0) {
      String book = shelf.remove(0);
      System.out.println(t.getName() + " : " + book + " is rented.");
      return book;
    }
    else {
      return null;
    }

  }

  public synchronized void returnBook(String book) {

    Thread t = Thread.currentThread();

    shelf.add(book);
    notifyAll();
    System.out.println(t.getName() + " : " + book + " has return.");
  }
}


class Student extends Thread {

  public Student(String name) {
    super(name);
  }

  @Override
  public void run() {
    
    try {
      String bookTitle = LibraryMain.library.rentalBook();
      if (bookTitle == null) {
        System.out.println("Not rented.");
        return;
      }
      sleep(5000); // reading book time
      LibraryMain.library.returnBook(bookTitle);
    } catch (InterruptedException e) {
      e.printStackTrace();
    }

    
  }
}



public class LibraryMain {
  
  public static Library library = new Library();

  public static void main(String[] args) {
    
    Student std1 = new Student("std1");
    Student std2 = new Student("std2");
    Student std3 = new Student("std3");
    Student std4 = new Student("std4");
    Student std5 = new Student("std5");
    Student std6 = new Student("std6");

    std1.start();
    std2.start();
    std3.start();
    std4.start();
    std5.start();
    std6.start();

  }
}
