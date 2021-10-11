package ch03;

public class CutomerTest {

  public static void main(String[] args) {
    
    /*
    Customer customerLee = new Customer();
    customerLee.setCustomerName("Lee");
    customerLee.setCustomerID(1001);
    customerLee.bonusPoint = 1000;

    customerLee.showCustomerInfo();*/

    VIPCustomer customerKim = new VIPCustomer(1002, "Kim");
    // customerKim.setCustomerName("Kim");
    // customerKim.setCustomerID(1002);
    customerKim.bonusPoint = 10000;
    customerKim.showCustomerInfo();

    Customer vc = new VIPCustomer(12345, "no-name");

    // Customer(parent)의 method만 접근할 수 있다.
    vc.customerName = "no_name";
  }
  
}
