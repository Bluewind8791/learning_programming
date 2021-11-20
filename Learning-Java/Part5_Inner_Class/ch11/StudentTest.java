package ch11;

public class StudentTest {

  public static void main(String[] args) {
    
    MyLogger myLogger = MyLogger.getLogger();

    // name = null
    String name = null;
    try {
      Student student = new Student(name);
      System.out.println(student);
    } catch (StudentNameFormatException e) {
      myLogger.warning(e.getMessage());
    }

    // name too long
    try {
      Student student = new Student("Edward Jon Kim Test");
      System.out.println(student);
    } catch (StudentNameFormatException e) {
      myLogger.warning(e.getMessage());
    }

    Student student = new Student("James");
    System.out.println(student);
  }
  
}
