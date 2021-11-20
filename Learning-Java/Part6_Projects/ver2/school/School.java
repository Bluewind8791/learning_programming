package ver2.school;

import java.util.ArrayList;

public class School {
  
  // singleton pattern
  private static School instance = new School();
  
  private School() {}
  
  public static School getInstance() {
    if (instance == null) {
      instance = new School();
    }
    return instance;
  }
  
  private ArrayList<Student> studentList = new ArrayList<>();
  private ArrayList<Subject> subjectList = new ArrayList<>();

  public void addStudent(Student student) {
    studentList.add(student);
  }
  public void addSubject(Subject subject) {
    subjectList.add(subject);
  }


  public ArrayList<Student> getStudentList() {
    return studentList;
  }
  public ArrayList<Subject> getSubjectList() {
    return subjectList;
  }
  public void setStudentList(ArrayList<Student> studentList) {
    this.studentList = studentList;
  }
  public void setSubjectList(ArrayList<Subject> subjectList) {
    this.subjectList = subjectList;
  }
}
