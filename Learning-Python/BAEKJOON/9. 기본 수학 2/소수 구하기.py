import sys
from math import *

input = sys.stdin.readline

low, high = map(int, input().split())


def IsPrimeNum(num):
    end = int(sqrt(num))
    if num <= 1:
        return False
    for i in range(2, end + 1):
        if num % i == 0:
            return False
    return True


primeList = []

for i in range(low, high + 1):
    if IsPrimeNum(i) == True:
        primeList.append(i)

for j in primeList:
    print(j)
