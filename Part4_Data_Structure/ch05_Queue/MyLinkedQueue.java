package ch05_Queue;

import ch03_LinkedList.MyLinkedList;
import ch03_LinkedList.MyListNode;

interface Queue {
  public void enQueue(String data);
  public String deQueue();
  public void printQueue();
}

public class MyLinkedQueue extends MyLinkedList implements Queue {

  MyListNode front;
  MyListNode rear;

  @Override
  public void enQueue(String data) {
    
    MyListNode newNode;

    if (isEmpty()) { // 처음으로 들어갈때
      newNode = addElement(data);
      front = newNode;
      rear = newNode;
    }
    else {
      newNode = addElement(data);
      rear = newNode;
    }

    System.out.println(newNode.getData() + " added");
  }

  @Override
  public String deQueue() {
    if (isEmpty()) {
      return null;
    }

    String data = front.getData();
    front = front.next;

    if (front == null) {
      rear = null;
    }

    return data;
  }

  @Override
  public void printQueue() {
    if (isEmpty()){
			System.out.println("Queue is Empty");
			return;
		}
		MyListNode temp = front;
		while(temp!= null){
			System.out.print(temp.getData() + ",");
			temp = temp.next;
		}
		System.out.println();
  }
}