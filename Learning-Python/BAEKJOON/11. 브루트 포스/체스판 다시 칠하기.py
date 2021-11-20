row, col = map(int, input().split())

chess = []
for _ in range(row):
    chess.append(list(input()))

rePaintList = []

for a in range(row - 8 + 1):
    for b in range(col - 8 + 1):
        W_beginCnt = 0
        B_beginCnt = 0
        for i in range(a, 8 + a):  # 세로 0 ~ 7
            for j in range(b, 8 + b):  # 가로 0 ~ 7
                if (i + j) % 2 == 0:
                    if chess[i][j] != "W":
                        W_beginCnt += 1
                    if chess[i][j] != "B":
                        B_beginCnt += 1
                else:
                    if chess[i][j] != "B":
                        W_beginCnt += 1
                    if chess[i][j] != "W":
                        B_beginCnt += 1
        rePaintList.append(W_beginCnt)
        rePaintList.append(B_beginCnt)

print(min(rePaintList))
