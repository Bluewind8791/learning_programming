package ch07;

public class Customer {
  
  String customerName;
  int customerAge;
  int travelPrice;

  public Customer(String customerName, int customerAge, int travelPrice) {
    this.customerName = customerName;
    this.customerAge = customerAge;
    this.travelPrice = travelPrice;
  }

  @Override
  public String toString() {
    return ("NAME: " + customerName + " AGE: " + customerAge + " COST: " + travelPrice);
  }

  public int getCustomerAge() {
    return customerAge;
  }
  public String getCustomerName() {
    return customerName;
  }
  public int getTravelPrice() {
    return travelPrice;
  }
  public void setCustomerAge(int customerAge) {
    this.customerAge = customerAge;
  }
  public void setCustomerName(String customerName) {
    this.customerName = customerName;
  }
  public void setTravelPrice(int travelPrice) {
    this.travelPrice = travelPrice;
  }
}
