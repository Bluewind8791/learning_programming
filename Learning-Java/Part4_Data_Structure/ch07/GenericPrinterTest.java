package ch07;

public class GenericPrinterTest {
  public static void main(String[] args) {
    
    Powder powder = new Powder();
    GenericPrinter<Powder> powderPrinter = new GenericPrinter<>();
    powderPrinter.setMaterial(powder);

    Powder p = powderPrinter.getMaterial();
    System.out.println(p);
    System.out.println(powderPrinter.toString());

    p.doPrinting(); // Material에 정의된 메서드 사용 가능
  }
}
