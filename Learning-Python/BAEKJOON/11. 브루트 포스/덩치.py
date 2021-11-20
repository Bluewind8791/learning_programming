N = int(input())

bigboysList = []

for _ in range(N):
    x = 0
    y = 0
    x, y = map(int, input().split())
    bigboysList.append({"weight": x, "tall": y, "rank": 1})

for i in range(N):
    for j in range(N):
        if bigboysList[i]["weight"] < bigboysList[j]["weight"] and bigboysList[i]["tall"] < bigboysList[j]["tall"]:
            bigboysList[i]["rank"] += 1

for i in range(N):
    print(bigboysList[i]["rank"], end=" ")
