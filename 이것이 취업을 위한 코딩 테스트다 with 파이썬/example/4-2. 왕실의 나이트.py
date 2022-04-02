# 왕실 정원은 8 * 8 좌표 평면이다. 왕실 정원의 특정한 칸에 나이트가 서있다.
# 나이트는 L자 형태로만 이동할 수 있으며 정원 밖으로는 나갈 수 없다
# 나이트는 특정한 위치에서 두가지 경우로 이동할 수 있다
# 1. 수평으로 두칸 이동한 뒤에 수직으로 한칸 이동
# 2. 수직으로 두칸 이동한 뒤에 수평으로 한칸 이동

# 왕실 정원의 나이트의 위치가 주어졌을 때, 나이트가 이동할 수 있는 경우의 수를 출력하시오
# 행은 1 ~ 8 / 열은 a ~ h 로 표현

# knight = input()
knight = "a1"

row = ["a", "b", "c", "d", "e", "f", "g", "h"]
column = ["1", "2", "3", "4", "5", "6", "7", "8"]

# x, y 좌표 구하기
for i in range(8):
    if knight[1] == str(i + 1):
        y = i

for j in row:
    if knight[0] == j:
        x = row.index(j)

# 수평으로 두칸 이동후 수직으로 한칸 이동 // 수직으로 두칸 이동 후 수평으로 한칸 이동의 모든 케이스
steps = [(2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]

nx, ny = 0, 0
result = 0


for i in range(8):
    nx = x + steps[i][0]
    ny = y + steps[i][1]
    if nx < 0 or ny < 0 or nx > 7 or ny > 7:
        continue
    result += 1

print(result)


# - ANSWER -

input_data = input()
row = int(input_data[1]) - 1
column = int(ord(input_data[0])) - int(ord("a"))

steps = [(2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]

result = 0
for step in steps:
    next_row = row + step[0]
    next_column = column + step[1]
    if next_row >= 0 or next_column >= 0 or next_row <= 7 or next_column <= 7:
        result += 1

print(result)
