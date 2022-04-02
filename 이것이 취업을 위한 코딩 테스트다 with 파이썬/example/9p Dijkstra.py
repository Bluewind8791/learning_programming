# 다익스트라 Dijkstra 최단경로 알고리즘

import sys

input = sys.stdin.readline
INF = int(1e9)  # 무한을 의미하는 값으로 10억 설정

# n = 노드의 개수, m = 간선의 개수
# n, m = map(int, input().split())
n = 6
m = 11

# 시작 노드 번호
# start = int(input())
start = 1

visited = [False] * (n + 1)
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

# 방문하지 않은 노드 중에서, 가장 최단거리가 짧은 노드의 번호를 반환
def get_smallest_node():
    min_value = INF
    # 최단 거리가 짧은 노드 저장
    index = 0

    # 모든 노드를 검사
    for i in range(1, n + 1):
        # 거리가 가장 짧고 방문하지 않은 노드라면
        if distance[i] < min_value and not visited[i]:
            min_value = distance[i]
            index = i
    return index


def dijkstra(start):
    # 시작 노드에 대해서 초기화
    distance[start] = 0
    visited[start] = True

    # in node graph
    for j in graph[start]:
        distance[j[0]] = j[1]

    # 시작 노드를 제외한 전체 n-1 개의 노드에 대해 반복
    for _ in range(n - 1):
        # 현재 최단 거리가 가장 짧은 노드를 꺼내어 방문처리
        now = get_smallest_node()
        visited[now] = True

        # 현재 노드와 연결된 다른 노드를 확인
        for j in graph[now]:
            cost = distance[now] + j[1]
            # 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은경우
            if cost < distance[j[0]]:
                distance[j[0]] = cost


dijkstra(start)

# 모든 노드로 가기 위한 최단 거리 출력
for i in range(1, n + 1):
    if distance[i] == INF:
        print("INFINITY")
    else:
        print(distance[i])

# 시간 복잡도는 O(V^)
# 따라서 코테의 최단 경로 문제에서 전체 노드의 개수가 5000개 이하라면 가능하지만
# 10000개 이상 넘어가는 문제라면 이 코드로 해결하기 어렵다
# 그러므로 개선된 다익스트라 알고리즘을 사용한다
