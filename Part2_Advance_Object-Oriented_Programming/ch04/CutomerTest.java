package ch04;

public class CutomerTest {

  public static void main(String[] args) {
    
    
    Customer customerLee = new Customer(1001, "Lee");
    customerLee.bonusPoint = 1000;

    int price = customerLee.calcPrice(1000);

    customerLee.showCustomerInfo();
    System.out.println("Lee 고객님의 최종 구매 가격: " + price);

    VIPCustomer customerKim = new VIPCustomer(1002, "Kim");
    customerKim.bonusPoint = 10000;
    price = customerKim.calcPrice(1000);
    customerKim.showCustomerInfo();
    System.out.println("Kim 고객님의 최종 구매 가격: " + price);


    Customer vc = new VIPCustomer(12345, "no-name");

    // Customer(parent)의 method만 접근할 수 있다.
    System.out.println(vc.calcPrice(1000)); // => 900
  }
  
}
