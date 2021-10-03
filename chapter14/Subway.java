package chapter14;

public class Subway {
  int subwayLine;
  int passengerCnt;
  int income;

  // input subway line
  public Subway(int subwayLine) {
    this.subwayLine = subwayLine;
  }
  
  // input income and 적용
  public void take(int income) {
    passengerCnt++;
    this.income += income;
  }

  // print info
  public void printSubwayInfo() {
    System.out.println(subwayLine+"호선의 승객: "+passengerCnt+" 수입: "+income);
  }


}
