package ch15;

public class TestCustomer {
  public static void main(String[] args) {
    
    Customer customer = new Customer();
    // customer.hello();
    // customer.order();
    // customer.buy();
    // customer.sell();

    Buy buyer = customer;
    buyer.order();
    buyer.buy();

    Sell seller = customer;
    seller.order();
    seller.sell();
  }
}
