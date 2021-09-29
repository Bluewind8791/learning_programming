package chapter08;

public class Customer {

  public String customerName;
  public int height;
  public int weight;
  public int age;
  public String gender;

  public void getCustomerInfo(String customerName, int height, int weight, int age, String gender) {
    this.customerName = customerName;
    this.height = height;
    this.weight = weight;
    this.age = age;
    this.gender = gender;
  }

  public String printCustomerInfo() {
    return ("키가 "+height+"이고 몸무게가 "+height+"킬로인 "+gender+"이 있습니다. 이름은 "+customerName+"이고 나이는 "+age+"세 입니다.");
  }
  
}


