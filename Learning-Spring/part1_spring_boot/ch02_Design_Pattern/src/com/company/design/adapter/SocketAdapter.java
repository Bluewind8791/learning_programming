package com.company.design.adapter;


public class SocketAdapter implements Electronic110V { // 110v implements로 한쪽 연결
  
  // 반대편 220V 연결할수 있게끔 만들고
  private Electronic220V electronic220v;

  public SocketAdapter(Electronic220V electronic220v) {
    this.electronic220v = electronic220v;
  }

  @Override
  public void powerOn() {
    electronic220v.connect();
  }
}
