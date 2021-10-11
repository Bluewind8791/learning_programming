package ch03;

public class Customer {

  // 하위 클래스는 접근 가능하나 / 외부에서는 접근 불가능한 protected 접근 제어자

  protected int customerID;
  protected String customerName;
  protected String customerGrade;
  int bonusPoint;
  double bonusRatio;

  /*
  public Customer() {
    bonusRatio = 0.01;
    customerGrade = "SILVER";
    System.out.println("Customer() called");
  }
  */

  public Customer(int customerID, String customerName) {
    this.customerID = customerID;
    this.customerName = customerName;

    bonusRatio = 0.01;
    customerGrade = "SILVER";
    System.out.println("Customer(int, String) called");
  }

  public int calcPrice(int price) {
    if (customerGrade == "SILVER") {
      bonusPoint += (price * bonusRatio);
    }
    else if (customerGrade == "VIP") {

    }
    return price;
  }

  public void showCustomerInfo() {
    if (customerGrade == "VIP") {
      System.out.println(customerName + "님의 등급은 " +customerGrade+ "이며, 보너스 적립 포인트는 " +bonusPoint+ "입니다.");
      System.out.println("또한 VIP 등급 특전으로 제품 구매시 10% 할인됩니다.");
    }
    else {
      System.out.println(customerName + "님의 등급은 " +customerGrade+ "이며, 보너스 적립 포인트는 " +bonusPoint+ "입니다.");
    }
  }

  public int getCustomerID() {
    return customerID;
  }
  public String getCustomerName() {
    return customerName;
  }
  public String getCustomerGrade() {
    return customerGrade;
  }
  public void setCustomerID(int customerID) {
    this.customerID = customerID;
  }
  public void setCustomerName(String customerName) {
    this.customerName = customerName;
  }
  public void setCustomerGrade(String customerGrade) {
    this.customerGrade = customerGrade;
  }

}