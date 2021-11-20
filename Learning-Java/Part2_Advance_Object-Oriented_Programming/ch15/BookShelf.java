package ch15;

// extends (상속) : 부모의 메서드를 그대로 사용 가능 오버라이딩 필요 없음
// implements (interface 상속) : 반드시 부모의 메서드를 오버라이딩, 다중상속 가능
public class BookShelf extends Shelf implements Queue {

  @Override
  public void enQueue(String title) {
    shelf.add(title);
    
  }

  @Override
  public String deQueue() {
    return shelf.remove(0);
  }

  @Override
  public int getSize() {
    return getCount();
  }
  
}
