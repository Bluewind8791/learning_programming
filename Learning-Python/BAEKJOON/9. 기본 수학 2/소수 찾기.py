import sys

input = sys.stdin.readline


def IsPrimeNum(num, n):
    if num <= 1:
        return False
    for i in range(2, (num // 2) + 1):
        if num % i == 0:
            return False
    return True


n = int(input())
num = list(map(int, input().split()))
cnt = 0

for i in range(n):
    if IsPrimeNum(num[i], n) == True:
        cnt += 1

print(cnt)
