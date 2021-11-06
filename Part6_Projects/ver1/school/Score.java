package ver1.school;


public class Score {
  
  int studentID;
  Subject subject;
  int point;

  // constructor
  public Score(int studentID, Subject subject, int point) {
    this.studentID = studentID;
    this.subject = subject;
    this.point = point;
  }

  public int getStudentID() {
    return studentID;
  }
  public Subject getSubject() {
    return subject;
  }
  public int getPoint() {
    return point;
  }
  public void setStudentID(int studentID) {
    this.studentID = studentID;
  }
  public void setSubject(Subject subject) {
    this.subject = subject;
  }
  public void setPoint(int point) {
    this.point = point;
  }




}
