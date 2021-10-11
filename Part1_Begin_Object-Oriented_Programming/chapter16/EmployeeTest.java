package chapter16;

public class EmployeeTest {
  
  public static void main(String[] args) {

    Employee lee = new Employee();
    lee.setEmployeeName("이순신");

    System.out.println(Employee.getSerialNum());
    
    Employee kim = new Employee();
    kim.setEmployeeName("KimSin");

    System.out.println("Kim Serial Number: " + lee.getEmployeeId());
    System.out.println("Lee Serial Number: " + kim.getEmployeeId());

    // static 은 공유한다.
  }
}
