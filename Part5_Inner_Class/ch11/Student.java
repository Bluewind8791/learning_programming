package ch11;

public class Student {
  
  private String studentName;
  MyLogger myLogger = MyLogger.getLogger();

  public Student(String studentName) {

    if (studentName == null) {
      throw new StudentNameFormatException("Name must not be null.");
    }
    if (studentName.split(" ").length > 3) {
      throw new StudentNameFormatException("Name is too long.");
    }

    this.studentName = studentName;
  }

  public String getStudentName() {
    myLogger.fine("Begin getStudentName()");
    return studentName;
  }
}
