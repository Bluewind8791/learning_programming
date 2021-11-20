package com.company.design.proxy;


public class BrowerProxy implements IBrowser {
  
  private String url;
  private Html html;

  public BrowerProxy(String url) {
    this.url = url;
  }

  @Override
  public Html show() {
    if (html == null) {
      this.html = new Html(url);
      System.out.println("Brower Proxy loading HTML from : " + url);
    }

    System.out.println("Brower Proxy use CACHE! HTML : " + url);
    return html;
  }
}
