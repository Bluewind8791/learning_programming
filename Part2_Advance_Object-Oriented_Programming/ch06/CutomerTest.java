package ch06;

import java.util.ArrayList;

public class CutomerTest {

  public static void main(String[] args) {
    
    ArrayList<Customer> customerList = new ArrayList<>();

    Customer customerT = new Customer(10010, "Tomas");
    Customer customerJ = new GoldCustomer(10011, "James");
    Customer customerE = new GoldCustomer(10012, "Edward");
    Customer customerP = new VIPCustomer(10013, "Percy");
    
    
    customerList.add(customerT);
    customerList.add(customerJ);
    customerList.add(customerE);
    customerList.add(customerP);

    for (Customer customer : customerList) {
      customer.showCustomerInfo();
    }
    
    int price = 10000;
    for (Customer customer : customerList) {
      int cost = customer.calcPrice(price);
      String name = customer.getCustomerName();
      int bonus = customer.bonusPoint;
      System.out.println(name +" have to pay "+ cost);
      System.out.println(name +"'s bonus point is "+ bonus);
    }
  }
  
}
