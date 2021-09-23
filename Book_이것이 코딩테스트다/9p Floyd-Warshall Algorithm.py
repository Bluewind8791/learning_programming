# 플로이드 워셜 알고리즘


# 다익스트라 알고리즘은 한지점에서 다른 특정 지점까지의 최단 경로를 구하는 최단 경로 알고리즘이나
# 플로이드 워셜은 모든 지점에서 다른 모든 지점까지의 최단 경로를 구해야하는 경우 사용

# 플로이드 워셜 알고리즘은 모든 노드에 대하여 다른 모든 노드로 가는 최단거리 정보를 담아야 하기 때문에
# 2차원 리스트를 이용하여 매번 O(N^)의 시간 소요 그러므로 총시간복잡도는 O(N^3)

INF = int(1e9)


# n = 노드의 개수, m = 간선의 개수
# n, m = map(int, input().split())
n = 4
m = 7

graph = [[INF] * (n + 1) for _ in range(n + 1)]

# 자기 자신에서 자기 자신으로 가는 비용은 0으로 초기화
for a in range(1, n + 1):
    for b in range(1, n + 1):
        if a == b:
            graph[a][b] = 0

"""
# 각 간선에 대한 정보를 입력받아 그 값으로 초기화
for _ in range(m):
    # a에서 b로 가는 비용은 c라고 설정
    a, b, c = map(int, input().split())
    graph[a][b] = c
"""

graph = [
    [1000000000, 1000000000, 1000000000, 1000000000, 1000000000],
    [1000000000, 0, 4, 1000000000, 6],
    [1000000000, 3, 0, 7, 1000000000],
    [1000000000, 5, 1000000000, 0, 4],
    [1000000000, 1000000000, 1000000000, 2, 0],
]

# 점화식에 따라 플로이드 워셜 알고리즘 수행
for k in range(1, n + 1):
    for a in range(1, n + 1):
        for b in range(1, n + 1):
            graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])


# 결과 출력
for a in range(1, n + 1):
    for b in range(1, n + 1):
        if graph[a][b] == INF:
            print("INFINITY", end=" ")
        else:
            print(f"node{[a]} to node{[b]} = {graph[a][b]}", end=" ")
    print()
