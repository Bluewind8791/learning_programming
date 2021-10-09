package chapter23;

// ArrayList library를 활용하자

import java.util.ArrayList;
import chapter21.Book;

public class ArrayListTest {
  public static void main(String[] args) {
    
    ArrayList<Book> library = new ArrayList<>();

    library.add(new Book("Title1", "Author1"));
    library.add(new Book("Title2", "Author2"));
    library.add(new Book("Title3", "Author3"));
    library.add(new Book("Title4", "Author4"));
    library.add(new Book("Title5", "Author5"));

    for(int i=0; i<library.size(); i++) {
      library.get(i).showInfo();
    }
  }
}
