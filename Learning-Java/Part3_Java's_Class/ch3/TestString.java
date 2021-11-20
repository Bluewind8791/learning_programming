package ch3;

public class TestString {
  public static void main(String[] args) {
    String java = new String("java");
    String android = new String("Android");

    System.out.println(System.identityHashCode(java)); // before concat 925858445
    java = java.concat(android);

    System.out.println(java); // JavaAndroid

    // java가 가르키는 주소가 달라짐
    System.out.println(System.identityHashCode(java)); // after concat 798154996

  }
}
