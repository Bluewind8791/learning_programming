kinds, sum = map(int, input().split())
CoinKinds = []
numOfCoin = 0


# 동전의 종류 입력받기
for _ in range(kinds):
    CoinKinds.append(int(input()))

k = 1
while True:
    if sum > CoinKinds[-k]:
        index = kinds - k
        break
    else:
        k += 1

i = 0
while index - i >= 0:
    numOfCoin += sum // CoinKinds[index - i]
    sum -= CoinKinds[index - i] * (sum // CoinKinds[index - i])
    i += 1

print(numOfCoin)
