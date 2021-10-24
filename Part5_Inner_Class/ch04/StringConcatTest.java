package ch04;

public class StringConcatTest {
  
  public static void main(String[] args) {

    // lambda식 방식 : StringConcatImp class 만드는 부분 생략됨
    String s1 = "Hello";
    String s2 = "World";
    StringConcat concat = (str1, str2) -> System.out.println(str1 + " " + str2);
    concat.makeString(s1, s2);


    // lambda식은 이렇게 익명 내부 클래스가 숨어있음 그래서 StringConcat class는 필요함
    // StringConcat concat2 = new StringConcat() {
    //   public void makeString(String s1, String s2) {};
    // };
    

    // 기존의 implement 하여 사용하는 방식
    StringConcatImp strConcat = new StringConcatImp();
    strConcat.makeString("Hello", "World");
  }
}
