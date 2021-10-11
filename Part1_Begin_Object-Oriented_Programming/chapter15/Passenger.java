package chapter15;

public class Passenger {

  String passengerName;
  int money;

  public Passenger(String passengerName, int money) {
    this.passengerName = passengerName;
    this.money = money;
  }

  public void printPassengerInfo() {
    System.out.println(passengerName+"님의 남은 돈은 "+money+"원 입니다.");
  }

  public void takeTaxi(int cost) {
    this.money -= cost;
  }


  
}
