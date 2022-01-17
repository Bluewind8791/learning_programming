# n가지 종류의 화폐가 있다
# 이 화폐의 개수를 최소한으로 이용해서 그 가치의 합이 m원이 되도록 한다
# 각 화폐는 몇개라도 사용할 수 있으며 순서만 다른것은 같은 경우의 수로 구분

# 2원 3원이 있을경우 15원을 만들기 위하여 3원 5개를 사용하는것이 가장 최소한의 화폐 개수이다
# 불가능할 경우 -1 출력

# +++ input +++
# n, m = map(int, input().split())
# coin = []
# for _ in range(n):
#     coin.append(int(input()))

# n = 2
# m = 17
# coin = [2, 3]

# n = 3
# m = 4
# coin = [3, 5, 7]

n = 3
m = 7
coin = [2, 3, 5]


# d[i] = 금액 i를 만들수있는 최소한의 화폐 개수
# 각 화폐 단위인 k 를 하나씩 확인하며
# d[i-k]를 만드는 방법이 존재하는 경우 d[i] = min(d[i], d[i-k]+1)


# DP Table
d = [99999] * (m + 1)

d[0] = 0

for i in coin:
    for j in range(1, m + 1):
        if d[j - i] != 99999:
            d[j] = min(d[j], d[j - i] + 1)

if d[m] == 99999:
    print(-1)
else:
    print(d[m])
