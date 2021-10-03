package chapter21;

public class BookTest {

  public static void main(String[] args) {
    
    Book[] library = new Book[5];

    // for (int i=0; i<library.length; i++) {
    //   System.out.println(library[i]);
    // }
    
    library[0] = new Book("Mountain1", "David");
    library[1] = new Book("Mountain2", "David");
    library[2] = new Book("Mountain3", "David");
    library[3] = new Book("Mountain4", "David");
    library[4] = new Book("Mountain5", "David");
    
    for(Book book : library) {
      System.out.println(book);
      book.showInfo();
    }
  }
  
}
