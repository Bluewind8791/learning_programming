package chapter15;

// Edward 가진돈 20000원 택시비 10000원
// 택시는 잘나간다 운수 택시

public class Taxi {
  String taxiCompany;
  int income;

  public Taxi(String taxiCompany, int income) {
    this.taxiCompany = taxiCompany;
    this.income += income;
  }

  public void printTaxiInfo() {
    System.out.println(taxiCompany+"수입은 "+income+"원 입니다.");
  }
}
