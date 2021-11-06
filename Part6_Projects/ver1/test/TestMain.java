package ver1.test;

import ver1.school.Score;
import ver1.school.School;
import ver1.school.Student;
import ver1.school.Subject;
import ver1.school.report.GenerateGradeReport;
import ver1.utils.Define;

public class TestMain {

  School school = School.getInstance();
  Subject korean;
  Subject math;

  GenerateGradeReport gradeReport = new GenerateGradeReport();

  public static void main(String[] args) {
    
    TestMain test = new TestMain();

    test.createSubject();
    test.createStudent();

    String report = test.gradeReport.getReport();
    System.out.println(report);
  }

  // 테스트 과목 생성
  public void createSubject() {
    korean = new Subject("Korean", Define.KOREAN);
    math = new Subject("Math", Define.MATH);

    school.addSubject(korean);
    school.addSubject(math);
  }

  public void createStudent() {
    Student student1 = new Student(211106, "Kang", korean);
    Student student2 = new Student(211107, "Kim", math);
    Student student3 = new Student(211108, "Shin", korean);
    Student student4 = new Student(211109, "Lee", korean);
    Student student5 = new Student(211110, "Hong", math);

    // school 리스트에 추가
    school.addStudent(student1);
    school.addStudent(student2);
    school.addStudent(student3);
    school.addStudent(student4);
    school.addStudent(student5);

    // 과목 수강생 리스트에 추가
    korean.register(student1);
    korean.register(student2);
    korean.register(student3);
    korean.register(student4);
    korean.register(student5);

    math.register(student1);
    math.register(student2);
    math.register(student3);
    math.register(student4);
    math.register(student5);

    addScoreStudent(student1, korean, 95);
    addScoreStudent(student1, math, 56);
    
    addScoreStudent(student2, korean, 95);
    addScoreStudent(student2, math, 95);
    
    addScoreStudent(student3, korean, 100);
    addScoreStudent(student3, math, 88);
    
    addScoreStudent(student4, korean, 89);
    addScoreStudent(student4, math, 95);

    addScoreStudent(student4, korean, 95);
    addScoreStudent(student4, math, 56);
  }

  public void addScoreStudent(Student student, Subject subject, int point) {

    Score score = new Score(student.getStudentID(), subject, point); // score에서 점수 추가
    student.addSubjectScore(score); // student 에서 점수 추가
  }
}
