from collections import deque


def recursive_func(i):
    if i == 100:
        return
    print(i, "번째 재귀함수에서", i + 1, "번째 재귀함수를 호출합니다.")
    recursive_func(i + 1)
    print(i, "번째 재귀함수를 종료합니다")


# recursive_func(1)


def gcd(a, b):
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)


# print(gcd(192,162))


graph = [[], [2, 3, 4], [1, 7], [1, 4, 5], [3, 5], [3, 4], [7], [2, 6, 8], [1, 7]]

visited = [False] * 9


def dfs(graph, v, visited):
    visited[v] = True
    print(v, end=" ")

    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)


# dfs(graph, 1, visited)


def bfs(graph, start, visited):
    queue = deque([start])  # queue 구현을 위해서 deque library 사용
    visited[start] = True

    while queue:
        v = queue.popleft()  # queue에서 하나의 원소를 뽑아서 출력하기
        print(v, end=" ")
        # 아직 방문 안한 인접한 원소들을 큐에 삽입
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True


bfs(graph, 1, visited)
