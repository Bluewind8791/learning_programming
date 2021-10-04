package chapter21;

public class ObjectCopyTest {
  
  public static void main(String[] args) {
    
    Book[] library = new Book[5];
    Book[] copyLibrary = new Book[5];

    library[0] = new Book("Mountain1", "David");
    library[1] = new Book("Mountain2", "David");
    library[2] = new Book("Mountain3", "David");
    library[3] = new Book("Mountain4", "David");
    library[4] = new Book("Mountain5", "David");
    
    System.arraycopy(library, 0, copyLibrary, 0, 5);

    System.out.println("+++ Copy +++");
    for(Book book : copyLibrary) {
      System.out.println(book);
      book.showInfo();
    }

  }
}
