package chapter00;
public class StudentTest {
  public static void main(String[] args) {
    
    Student studentLee = new Student();

    studentLee.studentNumber= 12345;
    studentLee.setStudentName("Lee");
    studentLee.address = "Seoul";

    studentLee.showStudentInfo();

    System.out.println(studentLee);

  }
  
}
