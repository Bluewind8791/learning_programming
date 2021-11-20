package ch2;

public class EqualsTest {
  
  public static void main(String[] args) throws CloneNotSupportedException {
    
    /*
    Student std1 = new Student(100, "Lee");
    Student std2 = new Student(100, "Lee");

    System.out.println(std1 == std2); // return false
    System.out.println(std1.equals(std2)); // return false / after override true

    System.out.println(std1.hashCode());
    System.out.println(std2.hashCode());
    // hashCode 둘이 다르게 나옴 (주소값 다름)
    // override 후 학번으로 return하여 같게만듦

    System.out.println(System.identityHashCode(std1));
    System.out.println(System.identityHashCode(std2));
    // original hash code 확인 방법


    // String str1 = new String("abc");
    // String str2 = new String("abc");
    // System.out.println(str1.equals(str2)); // return true

    // System.out.println(str1.hashCode());
    // System.out.println(str2.hashCode());
    // // same hash code
    */

    // clone() method
    Student std1 = new Student(100, "Lee");
    std1.setStudentName("Kim"); // 중간에 바꾸더라도 그대로 반영되어 clone 됨.
    Student copyStudent = (Student)std1.clone();
    System.out.println(copyStudent);


  }
}
