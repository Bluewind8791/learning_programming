package ver2.school.report;

import java.util.ArrayList;

import ver2.grade.BasicEvaluation;
import ver2.grade.GradeEvaluation;
import ver2.grade.MajorEvaluation;
import ver2.grade.PassFailEvaluation;
import ver2.school.School;
import ver2.school.Score;
import ver2.school.Student;
import ver2.school.Subject;
import ver2.utils.Define;

public class GenerateGradeReport {

  School school = School.getInstance();

  public static final String TITLE = " 수강생 학점\n";
  public static final String HEADER = "이름\t|  학번  \t| 중점과목\t| 점수  \n";
  public static final String LINE = "------------------------------------------------\n";

  // StringBuffer 클래스를 이용하여 모든 리포트의 내용을 만들고 toString() 호출로 String 클래스로 변환.
  private StringBuffer buffer = new StringBuffer();


  public String getReport() {

    // 모든 과목에 대한 학점 산출
    ArrayList<Subject> subjectList = school.getSubjectList();

    for (Subject subject : subjectList) {
      makeHeader(subject);
      makeBody(subject);
      makeFooter();
    }

    return buffer.toString(); // string 으로 변환하여 return
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
      buffer.append(student.getStudentName()+ "\t"); // 이름
      buffer.append("| ");
      buffer.append(student.getStudentID()+ "\t");  // 학번
      buffer.append("| ");
      buffer.append(student.getMajorSubject().getSubjectName() + "  \t"); // 중점과목
      buffer.append("| ");

      getScoreGrade(student, subject.getSubjectID()); // 학점 계산
      buffer.append("\n");
      buffer.append(LINE);
    }

  }


  public void makeFooter() {
    buffer.append("\n");
  }


  public void getScoreGrade(Student student, int subjectID) {

    ArrayList<Score> scoreList = student.getScoreList();
    int majorID = student.getMajorSubject().getSubjectID();

    GradeEvaluation[] gradeEvaluation = {new BasicEvaluation(), new MajorEvaluation(), new PassFailEvaluation()}; // 학점 평가 클래스들

    for (int i=0; i<scoreList.size(); i++) { // 학생이 가진 점수들
      
      Score score  = scoreList.get(i);

      // 현재 학점을 산출할 과목
      if (score.getSubject().getSubjectID() == subjectID) {

        String grade;

        if (score.getSubject().getGradeType() == Define.PF_TYPE) {
          grade = gradeEvaluation[Define.PF_TYPE].getGrade(score.getPoint()); // Pass Fail
        }
        else {
          // 중점 과목인 경우
          if (score.getSubject().getSubjectID() == majorID) {
            grade = gradeEvaluation[Define.SAB_TYPE].getGrade(score.getPoint()); // 중점과목의 경우
          } else {
            grade = gradeEvaluation[Define.AB_TYPE].getGrade(score.getPoint()); // 중점 과목이 아닌 경우
          }
        }

        buffer.append(score.getPoint());
        buffer.append(":");
        buffer.append(grade);
        buffer.append(" |");
      }
    }
  }
  
}
