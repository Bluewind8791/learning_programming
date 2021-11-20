package chapter00;
public class Student {
  
  public int studentNumber;
  public String studentName;
  public String address;
  public int grade;


  public void setStudentName(String name) {
    studentName = name;
  }

  public void showStudentInfo() {
    System.out.println("The Student " + studentName + "'s Student Number is "+  studentNumber);
  }

  // public Student(int studentNumber, String studentName, int grade) {

  //   this.studentNumber = studentNumber;
  //   this.studentName = studentName;
  //   this.grade = grade;
  // }

}


