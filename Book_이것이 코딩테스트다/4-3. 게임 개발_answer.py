n, m = map(int, input().split())

# map을 0으로 초기화
d = [[0] * m for _ in range(n)]

# 현재 캐릭터의 x y 좌표 입력받기

x, y, direction = map(int, input().split())
d[x][y] = 1

# [[0, 0, 0, 0],
#  [0, 1, 0, 0],
#  [0, 0, 0, 0],
#  [0, 0, 0, 0]]

# input map information
array = []
for i in range(n):
    array.append(list(map(int, input().split())))

# setting north east south west
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


# turn left
def turn_left():
    global direction
    direction -= 1
    if direction < 0:
        direction = 3


# start simulation
count = 1
turn_time = 0

while True:
    turn_left()
    nx = x + dx[direction]
    ny = y + dy[direction]

    # after turn, if not visited, move on
    if d[nx][ny] == 0 and array[nx][ny] == 0:
        d[nx][ny] = 1
        x = nx
        y = ny
        count += 1
        turn_time = 0
        continue

    # after turn, 정면이 막힌경우 turn
    else:
        turn_time += 1

    # if all blocked
    if turn_time == 4:
        nx = x - dx[direction]
        ny = y - dy[direction]
        # if can go back
        if array[nx][ny] == 0:
            x = nx
            y = ny

        # if back is ocean
        else:
            break

        turn_time = 0

print(count)
