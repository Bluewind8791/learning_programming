# N * M 의 맵으로 육지 또는 바다
# 캐릭터는 동서남북 중 한 곳을 바라본다
# 맵의 각 칸은 (y, x)로 나타내며 y는 북쪽으로부터 떨어진 칸의 개수 x는 서쪽으로부터 떨어진 칸의 개수

# 1. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 갈 곳을 정한다.
# 2. 캐릭터의 바로 왼쪽에 가보지않은 칸이 존재한다음 왼쪽으로 회전 후 한칸 전진,
#   왼쪽방향에 가보지않은 칸이 없다면 왼쪽 방향으로 회전만 수행하고 1로 돌아감
# 3. 만약 네 방향이 모두 이미 가본 칸이거나 바다이면, 바라보는 방향을 유지한 채로 한칸 뒤로 가서 1단계로 돌아간다.
#   이때 뒷칸이 바다이면 멈춘다.

# 캐릭터가 방문한 칸의 수를 출력하는 프로그램


# - input -
# n, m = map(int, input().split())
# x, y, d = map(int, input().split())
# game_map = []
# for _ in range(n):
#     game_map.append(list(map(int, input().split())))

n = 4
m = 4
x = 1
y = 1
d = 0

game_map = [[1, 1, 1, 1], [1, 0, 0, 1], [1, 1, 0, 1], [1, 1, 1, 1]]

notVisited = 0
visited = 2
ocean = 1

# d = {0: north, 1: east, 2: south, 3: west}
direction = [(0, -1), (1, 0), (0, 1), (-1, 0)]

new_d = d
result = 1

while True:
    # 시작지점에 visited 표시
    game_map[x][y] = visited

    # 동서남북 4방향 검사
    for _ in range(4):
        # 현 방향에서 왼쪽 탐사
        new_d -= 1
        if new_d < 0:
            new_d = 3
        dx = x + direction[new_d][0]
        dy = y + direction[new_d][1]

        # 만약 안가본 곳이라면
        if game_map[dx][dy] == notVisited:
            # 캐릭터 이동 후 반복문 탈출
            x = dx
            y = dy
            break

    # 4방향 다 막힌 경우 프로그램 종료
    if new_d == d:
        break
    else:  # 이동했을 경우
        result += 1
        d = new_d

print(result)
