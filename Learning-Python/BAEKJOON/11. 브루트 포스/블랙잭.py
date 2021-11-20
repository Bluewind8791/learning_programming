Ncard, M = map(int, input().split())
card = list(map(int, input().split()))

cardSumList = []

for i in range(Ncard - 2):
    for j in range(i + 1, Ncard - 1):
        for k in range(j + 1, Ncard):
            if card[i] + card[j] + card[k] <= M:
                cardSumList.append(card[i] + card[j] + card[k])

cardSumList.sort(reverse=True)
print(cardSumList[0])
