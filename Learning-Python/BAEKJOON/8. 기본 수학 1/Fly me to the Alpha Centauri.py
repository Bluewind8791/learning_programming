test = int(input())

for _ in range(test):
    x, y = map(int, input().split())
    distance = y - x
    move = 0  # 구하고자 하는 이동 횟수
    moving_distance = 1  # 이동 가능한 거리
    sum_move = 0  # 이동한 거리의 합
    while True:
        if sum_move >= distance:
            break
        move += 1
        sum_move += moving_distance
        if move % 2 == 0:
            moving_distance += 1
    print(move)
