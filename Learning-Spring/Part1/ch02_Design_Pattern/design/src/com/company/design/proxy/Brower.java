package com.company.design.proxy;


public class Brower implements IBrowser {
  
  private String url;
  public Brower(String url) {
    this.url = url;
  }

  @Override
  public Html show() {
    System.out.println("Brower loading HTML from : " + url);
    return new Html(url);
  }
  
}
