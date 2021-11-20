package ch11;

public class MyLoggerTest {
  
  public static void main(String[] args) {
    
    MyLogger logger = MyLogger.getLogger();
    logger.log("Log test ...");
  }
}
