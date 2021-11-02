package ch22;


class Bank {
  private int money = 10000;

  public void saveMoney(int save) {
    
    // block sync
    synchronized(this) {

      int m = getMoney();
  
      try {
        Thread.sleep(3000);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
  
      setMoney(m + save);
    }
  }

  public synchronized void withdraw(int minus) {

    int m = getMoney();

    try {
      Thread.sleep(300);
    } catch (InterruptedException e) {
      e.printStackTrace();
    }

    setMoney(m - minus);
  }


  public int getMoney() {
    return money;
  }
  public void setMoney(int money) {
    this.money = money;
  }

}



class Park extends Thread {
  
  @Override
  public void run() {
    synchronized(SyncMain.myBank) {
      System.out.println("Start save money.");
      SyncMain.myBank.saveMoney(3000);
      System.out.println("He saved money : " + SyncMain.myBank.getMoney());
    }
  }
}


class ParkWife extends Thread {
  @Override
  public void run() {
    synchronized(SyncMain.myBank) {
      System.out.println("Start withdraw money.");
      SyncMain.myBank.withdraw(1000);
      System.out.println("She withdraw money : " + SyncMain.myBank.getMoney());
    }
  }
}





public class SyncMain {
  
  public static Bank myBank = new Bank();

  public static void main(String[] args) {
    
    Park p = new Park();
    p.start();

    try {
      Thread.sleep(200);
    } catch (InterruptedException e) {
      e.printStackTrace();
    }

    ParkWife pw = new ParkWife();
    pw.start();
    
  }
}
