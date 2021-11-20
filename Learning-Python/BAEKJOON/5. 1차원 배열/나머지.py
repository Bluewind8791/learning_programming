import sys

input = sys.stdin.readline

lst = []
for _ in range(10):
    lst.append(int(input()))

# lst = [42, 84, 252, 420, 840, 126, 42, 84, 420, 126]

for i in range(10):
    lst[i] = lst[i] % 42

diff = 0

for j in range(0, 10):  # 0 ~ 8
    cnt = 0
    for k in range(j + 1, 10):
        if lst[j] == lst[k]:
            break
        else:
            cnt += 1
    if cnt == 10 - (j + 1):
        diff += 1

print(diff)
