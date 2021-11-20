import sys

input = sys.stdin.readline

result = 1

for _ in range(3):
    result *= int(input())

result = list(str(result))


for i in range(0, 10):
    cnt = 0
    for j in result:
        if str(i) == j:
            cnt += 1
    print(cnt)
