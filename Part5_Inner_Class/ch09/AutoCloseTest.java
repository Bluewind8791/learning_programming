package ch09;

public class AutoCloseTest {
  
  public static void main(String[] args) {
    
    AutoCloseableObj obj = new AutoCloseableObj();


    try (obj) {
      // 아무것도 안했는데 auto close 가 불림
      throw new Exception(); // exception 강제로 발생

    } catch (Exception e) {
      System.out.println("Exception...");
      // exception 발생하여도 auto closing 발생
    }

    System.out.println("MAIN function end...");
  }
}
