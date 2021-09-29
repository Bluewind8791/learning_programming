package chapter09;

public class SubjectTest {

  public static void main(String[] args) {
    Student lee = new Student(100, "Lee");
    Student kim = new Student(200, "Kim");

    lee.setKoreanSubject("국어", 99);
    lee.setMathSubject("수학", 23);
    kim.setKoreanSubject("국어", 84);
    kim.setMathSubject("수학", 51);

    lee.showScoreInfo();
    kim.showScoreInfo();

  }
  
}
