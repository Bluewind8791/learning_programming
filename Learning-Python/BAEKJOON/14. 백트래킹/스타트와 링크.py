import sys

input = sys.stdin.readline
sys.setrecursionlimit(100001)

# n = int(input())
# s = [list(map(int, input().split())) for _ in range(n)]

n = 4
s = [[0, 1, 2, 3], [4, 0, 5, 6], [7, 1, 0, 2], [3, 4, 5, 0]]

visited = [False for _ in range(n)]

minimum = int(10 ** 9)


def dfs(idx, depth):
    global minimum

    if depth == n // 2:
        team1, team2 = 0, 0
        for i in range(n):
            for j in range(n):
                if visited[i] and visited[j]:
                    team1 += s[i][j]
                elif not visited[i] and not visited[j]:
                    team2 += s[i][j]
        minimum = min(minimum, abs(team1 - team2))

    for i in range(idx, n):
        if visited[i]:
            continue
        visited[i] = True
        dfs(i + 1, depth + 1)
        visited[i] = 0


dfs(0, 0)
print(minimum)
