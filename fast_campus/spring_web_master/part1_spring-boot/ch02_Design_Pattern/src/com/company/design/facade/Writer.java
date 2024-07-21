package com.company.design.facade;

public class Writer {
  
  private String fileName;

  public Writer(String fileName) {
    this.fileName = fileName;
  }

  public void fileConnect() {
    String msg = String.format("[Writer] connect %s", fileName);
    System.out.println(msg);
  }

  public void fileWrite() {
    String msg = String.format("[Writer] read %s", fileName);
    System.out.println(msg);
  }

  public void fileDisconnect() {
    String msg = String.format("[Writer] disconnect %s", fileName);
    System.out.println(msg);
  }

  public void write() {
    String msg = String.format("[Writer] write %s", fileName);
    System.out.println(msg);
  }
}
