import sys
from math import *

input = sys.stdin.readline


def Prime_list(n):
    # 에라토스테네스의 체 초기화: n개 요소에 True 설정(소수로 간주)
    PrimeL = [True] * n

    # n의 최대 약수가 sqrt(n) 이하이므로 i=sqrt(n)까지 검사
    root = int(n ** 0.5)
    for i in range(2, root + 1):
        if PrimeL[i] == True:  # i가 소수인 경우
            for j in range(i + i, n, i):  # i이후 i의 배수들을 False 판정
                PrimeL[j] = False

    # 소수 목록 산출
    return [i for i in range(2, n) if PrimeL[i] == True]


def Goldbach(n):
    primeList = Prime_list(n)
    halfmax = max([i for i in range(len(primeList)) if primeList[i] <= n / 2])
    for i in range(halfmax, -1, -1):
        for j in range(i, len(primeList)):
            if primeList[i] + primeList[j] == n:
                return [primeList[i], primeList[j]]


for _ in range(int(input())):
    evenN = int(input())
    result = Goldbach(evenN)
    print(f"{result[0]} {result[1]}")
