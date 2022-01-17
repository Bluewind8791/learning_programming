# 개미전사가 메뚜기 마을의 식량창고를 공격한다
# 식량창고는 일직선으로 이어져있고 각 식량창고에는 정해진 수의 식량을 저장하고 있으며
# 들키지 않고 약탈하기 위해서는 최소한 한칸 떨어진 식량창고를 약탈


# +++ input +++
# n = int(input())
# k = list(map(int, input().split()))

n = 4
food = [1,3,1,5]

# DP table
d = [0] * 1001

# dynamic programming bottom-up


d[0] = food[0]
d[1] = max(food[0], food[1])

for i in range(2, n):
    d[i] = max(d[i-1], d[i-2]+food[i])

print(d[n - 1])