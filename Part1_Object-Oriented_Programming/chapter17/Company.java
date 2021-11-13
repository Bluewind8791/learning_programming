package chapter17;

// 싱글폰 패턴

public class Company {
  
  private static Company instance = new Company();

  private Company() {
  }

  public static Company getInstance() {
    if (instance == null) {
      instance = new Company();
    }
    return instance;
  }

}
