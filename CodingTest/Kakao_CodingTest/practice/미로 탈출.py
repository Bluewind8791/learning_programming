# N * M 크기의 미로에 갇혔고 미로에는 여러마리의 괴물이 있다
# 동빈이의 위치는 1,1 이며, 출구는 N, M의 위치에 존재하며 한번에 한칸씩 이동
# 괴물이 있는곳은 0, 없는 부분은 1
# 동빈이가 탈출하기위해 움직여야 하는 최소 칸 수는? (시작칸과 마지막칸 포함 계산)

from collections import deque


n = 5
m = 6

# n, m = map(int, input().split())

maze = [[1, 0, 1, 0, 1, 0], [1, 1, 1, 1, 1, 1], [0, 0, 0, 0, 0, 1], [1, 1, 1, 1, 1, 1], [1, 1, 1, 1, 1, 1]]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

start_x = 0
start_y = 0


def bfs(x, y):
    queue = deque()
    queue.append((x, y))

    while queue:  # queue가 빌때까지 반복
        x, y = queue.popleft()  # 큐에서 마지막을 뽑아서

        # 4가지 방향 확인
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or nx >= n or ny >= m or ny < 0:
                continue  # 벽인 경우 통째로 넘어감

            if maze[nx][ny] == 0:
                continue  # 괴물이 있으면 넘어감

            if maze[nx][ny] == 1:  # 처음 방문하는 노드
                maze[nx][ny] = maze[x][y] + 1
                queue.append((nx, ny))

    return maze[x][y]


print(bfs(start_x, start_y))
