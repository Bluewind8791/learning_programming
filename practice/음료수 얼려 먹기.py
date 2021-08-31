# - input -
# N * M 크기의 얼음틀
# 구멍이 뚫려있는 부분은 0
# 칸막이가 존재하는 부분은 1

# 구멍이 뚫려있는 부분끼리 상, 하, 좌, 우로 붙어있는 경우
# 서로 연결되어 있는 것으로 간주합니다.

# 얼음틀의 모양이 주어졌을 때 생성되는 아이스크림의 갯수를 구하는 프로그램

# visited n * m
# index 0,0 부터 탐색해서
# 값이 0이면서 방문하지 않았다면 방문


def dfs(graph, start, visited, depth):
    if depth == depth:
        return
    visited[start] = True

    for i in graph[start]:
        if not visited[i]:
            dfs(graph, i, visited, depth + 1)


graph = [[0, 0, 1, 1, 0], [0, 0, 0, 1, 1], [1, 1, 1, 1, 1], [0, 0, 0, 0, 0]]

N = 4
M = 5

visited = [False] * (M)
depth = N

dfs(graph, 1, visited, depth)
