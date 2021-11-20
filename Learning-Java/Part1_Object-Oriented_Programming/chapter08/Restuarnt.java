package chapter08;

public class Restuarnt {
  public static void main(String[] args) {
    
    Customer person1 = new Customer();

    person1.getCustomerInfo("Tomas", 180, 78, 37, "남성");
    System.out.println(person1.printCustomerInfo());

    DeliveryInfo order1 = new DeliveryInfo();
    order1.getDeliveryInfo(202011020003L, 01023450001, "서울시 강남구 역삼동 111-333", 20201102, 130258, 35000, 0003);
    System.out.println(order1.printDeliveryInfo());
  }
  
}
