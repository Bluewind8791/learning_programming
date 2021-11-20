import sys

input = sys.stdin.readline

c = int(input())

for _ in range(c):
    case = list(map(int, input().split()))
    sum = 0
    avg = 0
    percent = 0
    for i in range(1, len(case)):
        sum += case[i]
    avg = sum / case[0]
    for i in range(1, len(case)):
        if case[i] > avg:
            percent += 1
    print("%.3f%%" % ((percent / case[0]) * 100))
