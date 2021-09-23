# 개선된 다익스트라 알고리즘
# 시간복잡도 O(ElogV), V = node 개수, E = 간선 개수
# 개선된 다익스트라 알고리즘에서는 Heap 자료구조 사용

# Heap 설명
# 우선순위 큐 (Priority Queue)를 구현하는 자료구조
# 우선순위 큐는 우선순위가 가장 높은 데이터를 가장 먼저 삭제

# heapq 라이브러리 사용

# 우선순위 값을 표현할 때는 일반적으로 정수형 자료형의 변수 사용
# 최소 힙 Min Heap 최대 힙 Max Heap을 이용한다
# 최소 힙을 이용하는 경우 값이 낮은 데이터가 먼저 삭제
# 최대 힙을 이용하는 경우 값이 큰 데이터가 먼저 삭제

# 다익스트라 최단 경로 알고리즘은 비용이 적은 노드를 우선방문하므로
# 최소 힙 구조를 기반으로 우선순위 큐 라이브러리를 사용

# 또한 최소 힙을 최대 힙처럼 사용하기위하여 일부러 우선순위에 -를 붙여서 넣었다가
# 나중에 우선순위 큐에서 꺼낸 다음에 다시 -를 붙여서 원래의 값으로 돌리는 방식을 사용할 수 있다.

import heapq
import sys

input = sys.stdin.readline
INF = int(1e9)


# n = 노드의 개수, m = 간선의 개수
# n, m = map(int, input().split())
n = 6
m = 11

# 시작 노드 번호
# start = int(input())
start = 1

distance = [INF] * (n + 1)

"""
# 모든 간선정보 입력받기
graph = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b, c = map(int, input().split())
    # a번 노드에서 b번 노드로 가는 비용이 c
    graph[a].append((b, c))
"""

graph = [[], [(2, 2), (3, 5), (4, 1)], [(3, 3), (4, 2)], [(2, 3), (6, 5)], [(3, 3), (5, 1)], [(3, 1), (6, 2)], []]


def dijkstra(start):
    q = []
    # 시작 노드로 가기 위한 최단 경로는 0으로 설정하여 q에 삽입 (distance, node)
    heapq.heappush(q, (0, start))
    distance[start] = 0
    # queue 가 빌때까지 반복
    while q:
        # 가장 최단거리가 짧은 노드 꺼내기
        dist, now = heapq.heappop(q)

        # 현재 노드가 이미 처리된 적이 있다면 무시
        if distance[now] < dist:
            continue

        # 그렇지않다면 현재 노드와 연결된 다른 인접한 노드 확인
        for i in graph[now]:
            cost = dist + i[1]
            # 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))


dijkstra(start)


# 모든 노드로 가기 위한 최단 거리 출력
for i in range(1, n + 1):
    if distance[i] == INF:
        print("INFINITY")
    else:
        print(distance[i])
