# n개의 도시가 있다 각 도시는 보내고자 하는 메세지가 있는 경우 
# 다른 도시로 전보를 보내서 다른 도시로 해당 메세지를 전송한다
# 통로는 일방향이며, 메세지를 보낼때는 일정 시간이 소요된다.

# 도시 c에서 출발하여 각 도시사이에 설치된 통로를 거쳐 최대한 많이 퍼져나가야 한다
# 각 도시의 번호와 통로가 설치되어 잇는 정보가 주어졌을 때, 
# 도시 c에서 보낸 메세지를 받게되는 도시의 개수는 총 몇개이며 도시들이 모두 메세지를 받는데 걸리는 시간은 얼마인가

import sys
import heapq

input = sys.stdin.readline


# +++ input +++

# +++ input 1 +++
n = 3
m = 2
start = 1
graph = [[], [(2,4), (3,2)],[],[]]

# n, m, start = map(int, input().split())
# graph = [[] for _ in range(n+1)]
# for _ in range(m):
#   a, b, cost = map(int, input().split())
#   # a to b, cost
#   graph[a].append((b, cost))



# dijstra algorithm
# 1. INF 정의
INF = int(1e9)

# 2. distance 배열 INF로 초기화 및 생성
distance = [INF] * (n + 1)

# dijkstra function
def dijkstra(start):
  q = []
  heapq.heappush(q, (0, start))
  distance[start] = 0

  # queue 가 빌때까지 반복
  while q:
    dist, now = heapq.heappop(q)

    if distance[now] < dist:
      continue

    for i in graph[now]:
      cost = dist + i[1]
      if cost < distance[i[0]]:
        distance[i[0]] = cost
        heapq.heappush(q, (cost, i[0]))


dijkstra(start)

# +++ output +++
# 도달하는 도시의 총 개수와 총 걸리는 시간을 공백으로 구분하여 출력
count = 0
max_distance = 0
for d in distance:
  if d != INF:
    count += 1
    max_distance = max(max_distance, d)

print(count-1, max_distance)