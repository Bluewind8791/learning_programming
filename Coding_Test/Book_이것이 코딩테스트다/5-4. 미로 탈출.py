# n * m 크기의 미로를 탈출
# 시작 위치 (1, 1)
# 출구 (n, m)
# 괴물이 있는 부분은 0 없는 부분은 1
# 탈출을 위하여 움직어야 하는 최소 칸의 개수를 구하시오 ( 첫번쨰 칸 마지막 칸 포함)

# - input -
# n, m = map(int, input().split())
# maze = []
# for _ in range(n):
#     maze.append(list(map(int, input())))

from collections import deque

n = 5  # i
m = 6  # j
maze = [[1, 0, 1, 0, 1, 0], [1, 1, 1, 1, 1, 1], [0, 0, 0, 0, 0, 1], [1, 1, 1, 1, 1, 1], [1, 1, 1, 1, 1, 1]]

# 최단 경로는 BFS 알고리즘을 사용하면 효과적으로 풀 수 있다


dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]


def bfs(x, y):
    # deque library
    queue = deque()
    queue.append([x, y])

    # queue가 빌때 까지 반복
    while queue:
        # queue 에서 원소를 하나 뽑는다
        x, y = queue.popleft()
        print(x, y)

        # 4 방향 위치 확인
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            # 맵 범위를 벗어날 경우, 괴물이 있는 경우 무시
            if nx < 0 or ny < 0 or nx >= n or ny >= m or maze[nx][ny] == 0:
                continue
            # 괴물이 없고 방문 안한 곳인 경우
            if maze[nx][ny] == 1:
                # queue에 삽입
                queue.append([nx, ny])
                # 최단 경로 표시
                maze[nx][ny] = maze[x][y] + 1

    # 출구는 n-1, m-1 이므로 최단거리 반환
    return maze[n - 1][m - 1]


x = 0
y = 0

print(bfs(x, y))
