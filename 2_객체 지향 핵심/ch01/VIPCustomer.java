package ch01;

// 매출에 더 많이 기여하는 단골 고객
// 제품 살때 10% 할인
// 보너스 포인트 5% 부여
// 전문 상담원 배정

// extends Class
public class VIPCustomer extends Customer {

  double salesRatio;
  private String agentID;
  
  public VIPCustomer() {
    super(); // 상위클래스(Customer) 을 컴파일러가 자동적으로 super()을 불러내서
    // Customer() 을 불러낸다

    bonusRatio = 0.05;
    salesRatio = 0.1;
    customerGrade = "VIP";
  }

  public String getAgentID() {
    return agentID;
  }
  public void setAgentID(String agentID) {
    this.agentID = agentID;
  }
}
