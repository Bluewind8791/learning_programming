package chapter08;

public class DeliveryInfo {
  
  public long orderNum;
  public int customerPhoneNum;
  public String customerAddress;
  public int orderDate;
  public int orderTime;
  public int orderPrice;
  public int menu;
  
  public void getDeliveryInfo(long orderNum, int customerPhoneNum, String customerAddress, int orderDate, int orderTime, int orderPrice, int menu) {
    this.orderNum = orderNum;
    this.customerPhoneNum = customerPhoneNum;
    this.customerAddress = customerAddress;
    this.orderDate = orderDate;
    this.orderTime = orderTime;
    this.orderPrice = orderPrice;
    this.menu = menu;
  }

  public String printDeliveryInfo() {
    return 
      "주문 접수 번호 : "+orderNum+"\n주문 핸드폰 번호 : "+customerPhoneNum+"\n주문 집 주소 : "+customerAddress+
      "\n주문 날짜 : "+orderDate+"\n주문 시간 : "+orderTime+"\n주문 가격 : "+orderPrice+"\n메뉴 번호 : " + menu;
  }
}
