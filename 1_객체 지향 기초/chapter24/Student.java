package chapter24;

import java.util.ArrayList;

public class Student {
  
  int studentNum;
  String studentName;

  // class array
  ArrayList<Subject> subjectList;

  public Student(int studentNum, String studentName) {
    this.studentName = studentName;
    this.studentNum = studentNum;

    subjectList = new ArrayList<>();
  }

  public void addSubject(String subjectName, int score) {

    Subject sub = new Subject();
    sub.setSubject(subjectName);
    sub.setScore(score);

    subjectList.add(sub);
  }

  public void showStudentInfo() {
    int totalScore = 0;

    for (Subject subject : subjectList) {
      System.out.println("학생 "+studentName+"의 "+subject.getSubject()+"과목 성적은 "+subject.getScore()+"입니다.");
      totalScore += subject.getScore();
    }
    System.out.println("학생 "+studentName+"의 총점은 "+totalScore+"입니다.");
  }
}
