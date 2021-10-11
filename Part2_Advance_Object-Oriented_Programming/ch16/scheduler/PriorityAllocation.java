package ch16.scheduler;

public class PriorityAllocation implements Scheduler {
  
  @Override
  public void getNextCall() {
    System.out.println("상담 전화를 우선순위가 높은 고객 대기열에서 가져옵니다.");
  }

  @Override
  public void sendCallToAgent() {
    System.out.println("숙련도 높은 상담원에게 먼저 배분합니다.");
  }

}
