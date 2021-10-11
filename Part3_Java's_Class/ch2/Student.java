package ch2;

// implements Cloneable
public class Student implements Cloneable {
  
  private int studentNum;
  private String studentName;

  public Student(int studentNum, String studentName) {
    this.studentNum = studentNum;
    this.studentName = studentName;
  }

  public void setStudentName(String studentName) {
    this.studentName = studentName;
  }

  @Override
  public String toString() {
    return studentNum + ", " + studentName;
  }

  // 논리적으로 학번이 같으면 같다고 설정
  @Override
  public boolean equals(Object obj) {

    if (obj instanceof Student) {
      Student std = (Student) obj; // downcasting
      if (this.studentNum == std.studentNum) {
        return true;
      }
      else {
        return false;
      }
    }
    return false;
  }

  @Override
  public int hashCode() {
    return studentNum;
  }

  @Override
  protected Object clone() throws CloneNotSupportedException {
    return super.clone();
  }

}
