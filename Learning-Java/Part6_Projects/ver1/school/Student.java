package ver1.school;

import java.util.ArrayList;

public class Student {

  private int studentID;        // 학번
  private String studentName;   // 학생 이름
  private Subject majorSubject;  // 필수 과목

  // 학생의 성적 리스트
  ArrayList<Score> scoreList = new ArrayList<>();

  public Student(int studentID, String studentName, Subject majorSubject) {
    this.studentID = studentID;
    this.studentName = studentName;
    this.majorSubject = majorSubject;
  }

  // 성적표 array list에 추가
  public void addSubjectScore(Score score) {
    scoreList.add(score);
  }

  public int getStudentID() {
    return studentID;
  }
  public String getStudentName() {
    return studentName;
  }
  public Subject getMajorSubject() {
    return majorSubject;
  }
  public void setStudentID(int studentID) {
    this.studentID = studentID;
  }
  public void setStudentName(String studentName) {
    this.studentName = studentName;
  }
  public void setMajorSubject(Subject majorSubject) {
    this.majorSubject = majorSubject;
  }
  public ArrayList<Score> getScoreList() {
    return scoreList;
  }
  public void setScoreList(ArrayList<Score> scoreList) {
    this.scoreList = scoreList;
  }
  
}