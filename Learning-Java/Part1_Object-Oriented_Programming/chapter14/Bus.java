package chapter14;

public class Bus {
  int busNum;
  int passengerCnt;
  int income;

  public Bus(int busNum) {
    this.busNum = busNum;
  }

  public void take(int income) {
    this.income += income;
    passengerCnt++;
  }

  public void printBusInfo() {
    System.out.println(busNum+"의 버스 승객: "+passengerCnt+"명\n수입: "+income);
  }

}
