# 행을 선택하여 그 행에 포함된 카드들 중 가장 낮은 카드를 뽑는다
# 가장 높은 카드를 뽑는 사람이 이김.

import sys

n, m = map(int, input().split())

# n = 3
# m = 3
# data = [[3, 1, 2], [4, 1, 4], [2, 2, 2]]

result = 0

for _ in range(n):
    data = list(map(int, input().split()))
    if result < min(data):
        result = min(data)

print(result)
