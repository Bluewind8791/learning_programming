package ch11;

import java.io.IOException;
import java.util.logging.FileHandler;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.logging.SimpleFormatter;

public class MyLogger {
  
  //                                  식별자
  Logger logger = Logger.getLogger("myLogger");
  private static MyLogger instance = new MyLogger();

  // 3개의 File 이름 지정
  public static final String errorLog = "log.txt";
  public static final String warningLog = "warning.txt";
  public static final String fineLog = "fine.txt";

  // FileHandler 지정
  private FileHandler logFile = null;
  private FileHandler warningFile = null;
  private FileHandler fineFile = null;

  private MyLogger() {

    try {
      logFile = new FileHandler(errorLog, true); // true: append / false: overwrite
      warningFile = new FileHandler(warningLog, true);
      fineFile = new FileHandler(fineLog, true);

    } catch (SecurityException e) {
      System.out.println(e);
    } catch (IOException e) {
      System.out.println(e);
    }

    // 출력 format
    logFile.setFormatter(new SimpleFormatter());
    warningFile.setFormatter(new SimpleFormatter());
    fineFile.setFormatter(new SimpleFormatter());

    // setting log level
    logger.setLevel(Level.ALL); // 전체 로그에 대한 레벨

    fineFile.setLevel(Level.FINE); // FINE level 부터 찍어라
    warningFile.setLevel(Level.WARNING); // WARNING level 부터 찍어라

    logger.addHandler(logFile);
    logger.addHandler(warningFile);
    logger.addHandler(fineFile);
  }

  public static MyLogger getLogger() {
    // logger.finest("Start get logger");
    return instance;
  }


  public void log(String msg) {
    logger.finest(msg);
    logger.finer(msg);
    logger.fine(msg);
    logger.config(msg);
    logger.info(msg);
    logger.warning(msg);
    logger.severe(msg);
  }

  public void fine(String msg) {
    logger.fine(msg);
  }
  public void warning(String msg) {
    logger.warning(msg);
  }
  
}
