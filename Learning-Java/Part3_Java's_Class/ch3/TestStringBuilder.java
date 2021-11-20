package ch3;

public class TestStringBuilder {
  public static void main(String[] args) {
    String java = new String("java");
    String android = new String("Android");

    // before make buffer
    System.out.println(System.identityHashCode(java));

    StringBuilder buffer = new StringBuilder(java); // buffer 생성
    buffer.append(android); // buffer 뒤에 append

    String test = buffer.toString(); // toString으로 문자열변환
    System.out.println(test);

    // after make buffer, hash code has no difference
    System.out.println(System.identityHashCode(java));
  }
}
