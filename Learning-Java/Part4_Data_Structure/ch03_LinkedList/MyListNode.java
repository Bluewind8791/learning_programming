package ch03_LinkedList;

public class MyListNode {
  
  private String data;      // data
  public MyListNode next;   // 다음 node를 가리키는 link

  // 아무것도 안넣으면 null로 생성
  public MyListNode() {
    data = null;
    next = null;
  }

  // data만 넣으면 data만 넣어줌
  public MyListNode(String data) {
    this.data = data;
    this.next = null;
  }

  // data link 둘다 넣었을 때
  public MyListNode(String data, MyListNode link) {
    this.data = data;
    this.next = link;
  }

  public String getData() {
    return data;
  }
}
