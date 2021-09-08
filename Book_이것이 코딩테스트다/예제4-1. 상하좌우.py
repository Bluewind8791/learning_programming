# 여행자 A는 N * N 크기의 정사각형 공간 위에 서있다.
# 가장 왼쪽 위 좌표는 1,1
# 가장 오른쪽 좌표는 N, N에 해당한다
# 계획서가 주어졌을때 여행자가 최종적으로 도착할 지점의 좌표는?

# input
# n = int(input())
# plan = list(input().split())

n = 5
plans = ["R", "R", "R", "U", "D", "D"]


# moving L R U D
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
move_types = ["L", "R", "U", "D"]

x, y = 1, 1
nx, ny = 0, 0

for plan in plans:
    for move in range(4):
        if plan == move_types[move]:
            nx = x + dx[move]
            ny = y + dy[move]

        # 범위를 벗어나는 경우 무시
        if nx < 1 or ny < 1 or nx > n or ny > n:
            continue

        # 이동 수행
        x = nx
        y = ny

print(x, y)
