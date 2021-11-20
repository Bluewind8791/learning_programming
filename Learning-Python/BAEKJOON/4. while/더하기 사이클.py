import sys

input = sys.stdin.readline

n = int(input())
cycleNum = 0
cnt = 1

cycleNum = int("{0}{1}".format(n % 10, ((n // 10) + (n % 10)) % 10))

while True:
    if cycleNum == n:
        print(cnt)
        break
    cycleNum = int("{0}{1}".format(cycleNum % 10, ((cycleNum // 10) + (cycleNum % 10)) % 10))
    cnt += 1
