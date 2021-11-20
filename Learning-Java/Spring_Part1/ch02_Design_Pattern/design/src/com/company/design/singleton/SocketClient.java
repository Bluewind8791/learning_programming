package com.company.design.singleton;

public class SocketClient {
  
  private static SocketClient socketClient = null;

  private SocketClient() {
    // default 생성자 막기
  }

  public static SocketClient getInstance() {

    if (socketClient == null) {
      socketClient = new SocketClient();
      System.out.println("Socket get new Instance!");
    }
    return socketClient;
  }

  public void connect() {
    System.out.println("connected.");
  }
}
