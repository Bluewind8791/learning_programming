package chapter17;

import java.util.Calendar;

public class CompanyTest {

  public static void main(String[] args) {
    
    Company comInstance1 = Company.getInstance();
    Company comInstance2 = Company.getInstance();

    System.out.println(comInstance1);
    System.out.println(comInstance2);

    Calendar calendar = Calendar.getInstance(); // 싱글톤 패턴
  }
  
}
