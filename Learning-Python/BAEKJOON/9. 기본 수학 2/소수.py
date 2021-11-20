import sys

input = sys.stdin.readline

low = int(input())
high = int(input())


def IsPrimeNum(num):
    if num <= 1:
        return False
    for i in range(2, (num // 2) + 1):
        if num % i == 0:
            return False
    return True


primeList = []

for i in range(low, high + 1):
    if IsPrimeNum(i) == True:
        primeList.append(i)

if len(primeList) == 0:
    print(-1)
    exit()

print(sum(primeList))
print(min(primeList))
