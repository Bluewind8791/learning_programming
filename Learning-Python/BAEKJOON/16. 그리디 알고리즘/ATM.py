n = int(input())
# n = 5
time = list(map(int, input().split()))
# time = [3, 1, 4, 3, 2]

time.sort()
spendTime = 0

for i in range(n):
    for j in range(i + 1):
        spendTime += time[j]

print(spendTime)
