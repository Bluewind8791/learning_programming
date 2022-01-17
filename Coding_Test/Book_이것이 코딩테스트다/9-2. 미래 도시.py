# 공중 미래 도시에는 1번부터 N번까지의 회사가 있는데 특정 회사끼리는 서로 도로를 통해 연결되어 있다.
# 방문 판매원 A는 현재 1번 회사에 위치, X번 회사에 방문해 물건 판매

# 회사끼리 연결되어 있는 도로는 양방향으로 이동 가능
# 1만큼의 시간으로 이동 가능

# 판매원은 1번 회사에서 출발하여 K회사에 먼저 들른 뒤 X번 회사에 가서 물건을 판매하는것이 목표
# 회사 사이를 이동하게 되는 최소시간을 계산하는 프로그램

# +++ input +++
"""
n, m = map(int, input().split())
x, k = map(int, input().split())
graph = [(1, 2), (1, 3), (1, 4), (2, 4), (3, 4), (3, 5), (4, 5)]
"""

n = 5
m = 7
x = 4
k = 5

INF = int(1e9)

# 1. 2차원 그래프 생성 및 INF로 초기화
graph = [[INF] * (n + 1) for _ in range(n + 1)]

# 2. 자기자신의 거리 0으로 초기화
for a in range(1, n + 1):
    for b in range(1, n + 1):
        if a == b:
            graph[a][b] = 0


# 3. 각 간선에 대한 input 정보 graph에 반영
for _ in range(m):
    # a에서 b로 가는 비용은 1로 설정
    a, b = map(int, input().split())
    graph[a][b] = 1


# 4. Floyd-Warshall
for k in range(1, n + 1):
    for a in range(1, n + 1):
        for b in range(1, n + 1):
            graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])


# 5. print result
for a in range(1, n + 1):
    for b in range(1, n + 1):
        if graph[a][b] == INF:
            print("INFINITY", end=" ")
        else:
            print(f"회사{[a]}에서 회사{[b]}까지의 거리는 {graph[a][b]}", end=" ")
    print()
