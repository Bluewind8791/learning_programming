package ch03_LinkedList;

public class MyLinkedList {
  
  private MyListNode head; // first element
  int count;

  public MyLinkedList() {
    head = null;
    count = 0;
  }

  // element를 넣으려면 previous element를 알아야함
  public MyListNode addElement(String data) {

    MyListNode newNode; // 새로 들어갈 node

    // head가 비어있으면 head에 add
    if (head == null) {
      newNode = new MyListNode(data);
      head = newNode;
    }
    else {
      newNode = new MyListNode(data);
      // 맨 뒤 node를 찾기
      MyListNode temp = head; // 첫번째부터 탐색
      while (temp.next != null) { // 맨 끝에 다다를때 까지
        temp = temp.next;
      }
      temp.next = newNode;
    }

    count++;
    return newNode;
  }

  public MyListNode insertElement(int index, String data) {
    MyListNode tempNode = head;
    MyListNode preNode = null;

    MyListNode newNode = new MyListNode(data);

    // out of range
    if (index < 0 || index > count) {
      return null;
    }

    if (index == 0) { // insert head
      newNode.next = head;
      head = newNode;
    }
    else {
      for (int i=0; i<index; i++) { // find previous node
        preNode = tempNode;
        tempNode = tempNode.next;
      }
      newNode.next = preNode.next;
      preNode.next = newNode;
    }

    count++;
    return newNode;
  }

  public MyListNode removeElement(int index) {

    MyListNode tempNode = head;
    MyListNode preNode = null;

    if (index == 0) {
      head = tempNode.next; // insert head
    }
    else {
      for (int i=0; i<index; i++) { // find previous node
        preNode = tempNode;
        tempNode = tempNode.next;
      }
      preNode.next = tempNode.next;
    }
    count--;
    return tempNode;
  }

  public String getElement(int position)
	{
		int i;
		MyListNode tempNode = head;
		
		if(position >= count ){
			System.out.println("검색 위치 오류 입니다. 현재 리스트의 개수는 " + count +"개 입니다.");
			return new String("error");
		}
		
		if(position == 0){  //맨 인 경우

			return head.getData();
		}
		
		for(i=0; i<position; i++){
			tempNode = tempNode.next;
			
		}
		return tempNode.getData();
	}

	public MyListNode getNode(int position)
	{
		int i;
		MyListNode tempNode = head;
		
		if(position >= count ){
			System.out.println("검색 위치 오류 입니다. 현재 리스트의 개수는 " + count +"개 입니다.");
			return null;
		}
		
		if(position == 0){  //맨 인 경우

			return head;
		}
		
		for(i=0; i<position; i++){
			tempNode = tempNode.next;
			
		}
		return tempNode;
	}

	public void removeAll()
	{
		head = null;
		count = 0;
		
	}
	
	public int getSize()
	{
		return count;
	}
	
	public void printQueue()
	{
		if(count == 0){
			System.out.println("출력할 내용이 없습니다.");
			return;
		}
		
		MyListNode temp = head;
		while(temp != null){
			System.out.print(temp.getData());
			temp = temp.next;
			if(temp!=null){
				System.out.print("->");
			}
		}
		System.out.println("");
	}
	
	public boolean isEmpty()
	{
		if(head == null) return true;
		else return false;
	}
}
