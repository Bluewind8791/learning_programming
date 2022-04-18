# 탐색 알고리즘


## DFS

- Depth-First-Search : 깊이 우선 탐색
- 그래프에서 깊은 부분을 우선적으로 탐색하는 알고리즘이다


### 그래프

- 그래프는 node(노드) 와 edge(간선)으로 표현되며, 이떄 노드를 vertex(정점)이라고도 한다.
- 그래프 탐색이란 하나의 노드를 시작으로 다수의 노드를 방문하는 것을 말한다.
- 두 노드가 간선으로 연결되어 있다면 '두 노드는 인접하다'라고 한다.

프로그래밍에서 그래프를 표현하는 방법

- 인접 행렬 : 2차원 배열로 그래프의 연결 관계를 표현
- 인접 리스트 : 리스트로 그래프의 연결 관계를 표현

```java
// 인접 행렬 방식 예제
int final static INF = 999999999;

int[][] graph = {
    {0, 1, 2},
    {7, 0, INF},
    {5, INF, 2}
}
```


```py
# 인접 리스트 방식 예제
graph = [[] for _ in range(3)]

# 노드에 연결된 노드 정보 저장(노드, 거리)
graph[0].append((1,7))
graph[0].append((2,5))
graph[1].append((0,7))
graph[2].append((0,5))
```
```java
// 인접 리스트 방식 예제
ListGraph adjList = new ListGraph(3);

adjList.put(1, 2);
adjList.put(1, 3);
adjList.put(2, 3);
adjList.put(2, 4);
adjList.put(3, 4);
adjList.put(3, 5);
adjList.put(4, 5);
adjList.put(4, 6);
```


### 스택 자료구조를 이용한 DFS 동작 과정

1. 탐색 시작 노드를 스택에 삽입하고 방문 처리
2. 스택의 최상단 노드에 방문하지 않은 인접 노드가 있으면, 그 인접 노드를 스택에 넣고 방문 처리를 한다. 방문하지 않은 인접 노드가 없으면 스택에서 최상단 노드를 꺼낸다.
3. 2번의 과정을 더 이상 수행할 수 없을때 까지 반복.


### DFS 예제

```py
# DFS 메서드 정의
def dfs(graph, v, visited):
    # 현재 노드 방문 처리
    visited[v] = True
    print(v, end=' ')
    # 현재 노드와 연결된 다른 노드를 재귀적으로 방문
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)
    
# 각 노드가 연결된 정보를 리스트 자료형으로 표현(2차원 리스트)
graph = [
    [],
    [2,3,8],
    [1,7],
    [1,4,5],
    [3,5],
    [3,4],
    [7],
    [2,6,8],
    [1,7]
]

# 각 노드가 방문된 정보를 리스트 자료형으로 표현 (1차원 리스트)
visited = [False] * 9

# 정의된 DFS 함수 호출
dfs(graph, 1, visited)
```

```java
boolean[] vistied = new boolean[9];

int[][] graph = {
    {},
    {2, 3, 8},
    {1, 7},
    {1, 4, 5},
    {3, 5},
    {3, 4},
    {7},
    {2, 6, 8},
    {1, 7}
};

// DFS 사용 할 스택
Stack<Integer> stack = new Stack<>();

// 시작 노드를 스택에 넣기
stack.push(1);
// 시작 노드 방문 처리.
visited[1] = true;

// 스택이 비어있지 않으면 계속 반복
while (!stack.isEmpty()) {
    // 스택에서 하나를 꺼낸다
    int nodeIndex = stack.pop();

    // 방문 노드 출력
    System.out.println(nodeIndex + " -> ");

    // 꺼낸 노드와 인접한 노드 찾기
    for (int linkedNode : graph[nodeIndex]) {
        // 인접한 노드를 방문하지 않았을 경우에 스택에 넣고 방문 처리
        if (!visited[linkedNode]) {
            stack.push(linkedNode);
            visited[linkedNode] = true;
        }
    }
}
```


---


## BFS

- BFS(Breadth First Search) 알고리즘
- **'너비 우선 탐색'**의 의미를 가집니다.
- **가까운 노드부터 탐색하는 알고리즘**
- 선입선출 방식의 큐 자료구조를 이용하는것이 정석.


### 동작 방식

1. 탐색 시작 노드를 큐에 삽입하고 방문 처리.
2. 큐에서 노드를 꺼내 해당 노드의 인접 노드 중에서 방문하지 않은 노드를 모두 큐에 삽입하고 방문 처리.
3. 2의 과정을 더이상 수행할 수 없을때 까지 반복.


### 예제

```py
from collections import deque

# BFS 메서드 정의
def bfs(graph, start, visited):
    # 큐 구현을 위해 deque 라이브러리 사용
    queue = deque([start])
    # 현재 노드를 방문 처리
    visited[start] = True
    # 큐가 빌 때 까지 반복
    while queue:
        # 큐에서 하나의 원소를 뽑아 출력
        v = queue.popleft()
        print(v, end=' ')
        # 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True

# 각 노드가 연결된 정보를 리스트 자료형으로 표현(2차원 리스트)
graph = [
    [],
    [2,3,8],
    [1,7],
    [1,4,5],
    [3,5],
    [3,4],
    [7],
    [2,6,8],
    [1,7]
]

# 각 노드가 방문된 정보를 리스트 자료형으로 표현 (1차원 리스트)
visited = [False] * 9

# 정의된 BFS 함수 호출
bfs(graph, 1, visited)
```

```java
```