n = int(input())

for _ in range(n):
    sum = 0
    score = list(input())
    if score[0] == "O":
        score[0] = int(1)
    elif score[0] == "X":
        score[0] = int(0)
    for i in range(1, len(score)):
        if score[i] == "O":
            score[i] = int(1) + int(score[i - 1])
        elif score[i] == "X":
            score[i] = int(0)
    for k in score:
        sum += k
    print(sum)
