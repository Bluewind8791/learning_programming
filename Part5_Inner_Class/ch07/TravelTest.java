package ch07;

import java.util.ArrayList;
import java.util.List;

public class TravelTest {
  public static void main(String[] args) {
    
    Customer customerLee = new Customer("이순신", 40, 100);
    Customer customerKim = new Customer("김유신", 20, 100);
    Customer customerHong = new Customer("홍길동", 13, 50);

    List<Customer> customerList = new ArrayList<Customer>();
    customerList.add(customerLee);
    customerList.add(customerKim);
    customerList.add(customerHong);

    // * 스트림을 활용한 연산 수행
    System.out.println("== 고객 명단 ==");
    customerList.stream().map(c -> c.getCustomerName()).forEach(name -> System.out.println(name));

    System.out.println("\n== 여행 총 비용 ==");
    System.out.println("총 비용: "+customerList.stream().mapToInt(c -> c.getTravelPrice()).sum() + "만원");

    System.out.println("\n== 20세 이상 고객 ==");
    //                    filter로 20세 이상을 가져와서 필터링          map으로 이름을 가져옴            정렬수행   각각의 이름 출력
    customerList.stream().filter(age -> age.getCustomerAge() >= 20).map(c -> c.getCustomerName()).sorted().forEach(name -> System.out.println(name));
  }
}
