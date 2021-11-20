package ch15;

import java.util.ArrayList;

// 물건을 담아두는 장
public class Shelf {
  
  // 상속 받을수 잇는 protected
  protected ArrayList<String> shelf;

  public Shelf() {
    shelf = new ArrayList<>();
  }

  public ArrayList<String> getShelf() {
    return shelf;
  }
  public int getCount() {
    return shelf.size();
  }

}
