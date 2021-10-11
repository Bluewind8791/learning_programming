package chapter14;

public class PrintTrafficInfo {

  public static void main(String[] args) {

    Student james = new Student("James", 5000);
    Student tomas = new Student("Tomas", 10000);
    
    Bus bus100 = new Bus(100);
    Bus bus1024 = new Bus(1024); // 이런식으로 여러개의 버스 객체 생성 가능
    Subway sub2 = new Subway(2);
    
    james.takeBus(bus100);
    tomas.takeSubway(sub2);
  
    james.showInfo();
    tomas.showInfo();

    bus100.printBusInfo();
    bus1024.printBusInfo();
    sub2.printSubwayInfo();
    
  }


}


