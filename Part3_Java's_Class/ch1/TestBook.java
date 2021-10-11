package ch1;

class Book {

  private String title;
  private String author;

  public Book(String title, String author) {
    this.title = title;
    this.author = author;
  }

  @Override
  public String toString() {
    return title + ", " + author;
  }
}


public class TestBook {
  public static void main(String[] args) {
    Book book = new Book("Demian", "헤르만 헤세");

    System.out.println(book); // ch1.Book@2f92e0f4
    // after toString overriding => Demian, 헤르만 헤세

    String str = new String("Testing");
    System.out.println(str); // Testing 이라고 문자열이 나옴 .toString()이 오버라이딩되어 있음.
  }
}