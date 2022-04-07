# Chapter 5

## 탐색 (Search)

- 많은 양의 데이터 중에서 원하는 데이터를 찾는 과정.
- 대표적으로 DFS와 BFS 알고리즘이 있다.

## 자료구조 (Data Structure)

- 데이터를 표현하고 관리하고 처리하기 위한 구조
- 자료구조의 기초 개념으로 Stack 과 Queue 가 있다.
- 이 개념에는 두가지 핵심 함수로 구성된다.
  - Push : 데이터 삽입
  - Pop : 데이터 삭제

- Overflow : 특정한 자료구조가 수용할 수 있는 데이터의 크기를 넘어선 상태에서 Push 했을 때.
- Underflow : 데이터가 전혀 들어가있지 않은 상태에서 Pop을 수행하였을 때.

## Stack

- 스택은 박스 쌓기에 비유할 수 있다.
- 선입후출(First In Last Out) 구조 또는 후입선출(Last In First Out) 구조라고 한다.

```java
import java.util.Stack;

public class StackExample {
	public static void main(String[] args) {

		Stack<String> stack = new Stack<>();

		// Stack에 데이터 추가
		stack.push("Data1");
		stack.push("Data2");
		stack.push("Data3");

		// Stack에서 데이터 꺼내기
		System.out.println(stack.pop());

		// Stack의 최상단 값 출력(제거하지 않음)
		System.out.println(stack.peek());
	}
}
```

- java 에서의 stack 사용법

## Queue

- 큐는 대기줄에 비유할 수 있다.
- 선입선출(First In First Out) 구조라고 한다.

```java
import java.util.LinkedList;
import java.util.Queue;

public class QueueExample {
    public static void main(String[] args) {

        Queue<String> queue = new LinkedList<String>();

        // Queue에 데이터 추가
        queue.add("Data1");
        queue.add("Data2");

        // 결과 출력
        System.out.print(queue);

        // 맨 앞의 값 삭제
        queue.poll();
    }
}
```

- java 에서의 queue 사용법 (`LinkedList`로 생성)

## Recursice Function

- 재귀 함수란 자기 자신을 다시 호출하는 함수

```java
public void recursive() {
    System.out.print("재귀 함수를 호출합니다.");
    recursive();
}
```

- 위의 예제는 무한히 재귀함수를 호출한다.
- 이를 방지하기 위해서는 종료 조건을 반드시 명시해야 한다.

```java
public void recursive(int count) {
    if (count == 100) {
        return
    }
    System.out.print(count+"번째 재귀 함수를 호출합니다.");
    recursive(count + 1);
}

public static void main(String[] args) {
    recursive(1);
}
```

- 컴퓨터 내부에서 재귀 함수의 수행은 stack 자료구조를 이용한다.
- 따라서 스택 자료구조를 활용해야 하는 상당수 알고리즘은 재귀함수를 이용해서 간편하게 구현할 수 있다.