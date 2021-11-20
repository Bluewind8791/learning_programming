package ver2.school;

import java.util.ArrayList;

import ver2.utils.Define;

public class Subject {
  
  private String subjectName; // 과목 이름
  private int subjectID;      // 과목 id
  private int gradeType;      // 평가방법

  // 수강신청한 학생 리스트
  ArrayList<Student> studentList = new ArrayList<>();

  public Subject(String subjectName, int subjectID) {
    this.subjectName = subjectName;
    this.subjectID = subjectID;
    this.gradeType = Define.AB_TYPE;
  }

  // 과목 수강신청 메서드
  public void register(Student student) {
    studentList.add(student);
  }

  public int getSubjectID() {
    return subjectID;
  }
  public String getSubjectName() {
    return subjectName;
  }
  public int getGradeType() {
    return gradeType;
  }
  public void setSubjectID(int subjectID) {
    this.subjectID = subjectID;
  }
  public void setSubjectName(String subjectName) {
    this.subjectName = subjectName;
  }
  public void setGradeType(int gradeType) {
    this.gradeType = gradeType;
  }
  public ArrayList<Student> getStudentList() {
    return studentList;
  }
  public void setStudentList(ArrayList<Student> studentList) {
    this.studentList = studentList;
  }
  

}


