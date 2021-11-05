package school.report;

import java.util.ArrayList;

import grade.BasicEvaluation;
import grade.GradeEvaluation;
import grade.MajorEvaluation;
import school.School;
import school.Score;
import school.Student;
import school.Subject;

public class GenerateGradeReport {

  School school = School.getInstance();

  public static final String TITLE = "수강생 학점\n";
  public static final String HEADER = " 이름  |  학번  |중점과목| 점수   \n";
  public static final String LINE = "------------------------------------\n";

  // StringBuffer 클래스를 이용하여 모든 리포트의 내용을 만들고 toString() 호출로 String 클래스로 변환.
  private StringBuffer buffer = new StringBuffer();

  public String getReport() {

    // 모든 과목에 대한 학점 산출
    ArrayList<Subject> subjectList = school.getSubjectList();
    for (Subject subject : subjectList) {
      
    }
  }

  public void makeHeader(Subject subject) {
    buffer.append(GenerateGradeReport.LINE);
    buffer.append("\t" + subject.getSubjectName());
    buffer.append(GenerateGradeReport.TITLE);
    buffer.append(GenerateGradeReport.HEADER);
    buffer.append(GenerateGradeReport.LINE);
  }

  public void makeBody(Subject subject) {

    ArrayList<Student> studentList = subject.getStudentList(); // 각 과목의 학생들

    for(int i=0; i<studentList.size(); i++) {
      Student student = studentList.get(i);
      buffer.append(student.getStudentName());
      buffer.append(" | ");
      buffer.append(student.getStudentID());
      buffer.append(" | ");
      buffer.append(student.getMajorSubject().getSubjectName() + "\t");
      buffer.append(" | ");

      getScoreGrade() // 학점 계산
    }

  }


  public void getScoreGrade(Student student, int subjectID) {
    ArrayList<Score> scoreList = student.getScoreList();
    int majorID = student.getMajorSubject().getSubjectID();

    GradeEvaluation[] gradeEvaluation = {new BasicEvaluation(), new MajorEvaluation()}; // 학점 평가 클래스들

    for (int i=0; i<scoreList.size(); i++) { // 학생이 가진 점수들
      
    }
  }
  
}
