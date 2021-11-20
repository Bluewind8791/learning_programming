import sys
from math import *

input = sys.stdin.readline


def Prime_list(start, n):
    # 에라토스테네스의 체 초기화: n개 요소에 True 설정(소수로 간주)
    PrimeL = [True] * n

    # n의 최대 약수가 sqrt(n) 이하이므로 i=sqrt(n)까지 검사
    root = int(n ** 0.5)
    for i in range(2, root + 1):
        if PrimeL[i] == True:  # i가 소수인 경우
            for j in range(i + i, n, i):  # i이후 i의 배수들을 False 판정
                PrimeL[j] = False

    # 소수 목록 산출
    return [i for i in range(start, n) if PrimeL[i] == True]


while True:
    n = int(input())
    if n == 0:
        break
    primeList = Prime_list(n + 1, n * 2 + 1)
    print(len(primeList))


# ###### time out ######
# def IsPrimeNum(num):
#     end = int(sqrt(num))
#     if num <= 1:
#         return False
#     for i in range(2, end + 1):
#         if num % i == 0:
#             return False
#     return True


# while True:
#     n = int(input())
#     if n == 0:
#         break
#     primeList = []

#     for i in range(n + 1, (n * 2) + 1):
#         if IsPrimeNum(i) == True:
#             primeList.append(i)

#     print(len(primeList))
