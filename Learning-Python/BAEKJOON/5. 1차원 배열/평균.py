import sys

input = sys.stdin.readline

n = int(input())

score = list(map(int, input().split()))

max = max(score)

for i in range(n):
    score[i] = score[i] / max * 100

sum = 0
for j in score:
    sum += j

print(sum / n)
