package chapter15;

public class PrintInfo {
  public static void main(String[] args) {

    int taxifee = 10000;

    Passenger edward = new Passenger("Edward", 20000);

    edward.takeTaxi(taxifee);
    edward.printPassengerInfo();

    Taxi taxi = new Taxi("잘나간다 운수", taxifee);
    taxi.printTaxiInfo();
  }
  
}
