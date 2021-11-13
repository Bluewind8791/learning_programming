package com.company.design.aop;

import com.company.design.proxy.Html;
import com.company.design.proxy.IBrowser;

public class AopBrower implements IBrowser {
  
  private String url;
  private Html html;

  // Runnable functional interface, run() method
  private Runnable before;
  private Runnable after;

  public AopBrower(String url, Runnable before, Runnable after) {
    this.url = url;
    this.before = before;
    this.after = after;
  }

  @Override
  public Html show() {
    before.run();;

    if (html == null) {
      this.html = new Html(url);
      System.out.println("AOP Brower HTML loading from : " + url);
      try {
        Thread.sleep(1500);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }

    after.run();
    System.out.println("AOP Brower HTML cache : " + url);
    return null;
  }
}
