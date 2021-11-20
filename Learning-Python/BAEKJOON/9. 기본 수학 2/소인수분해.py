import sys

input = sys.stdin.readline

n = int(input())

i = 2
while n != 1:
    if n % i == 0:
        n = n // i
        print(i)
    else:
        i += 1


############ time out ############

# if n == 0:
#     exit()

# def IsPrimeNum(num):
#     if num <= 1:
#         return False
#     for i in range(2, (num // 2) + 1):
#         if num % i == 0:
#             return False
#     return True


# PrimeNList = []

# for i in range(2, n // 2):
#     if IsPrimeNum(i) == True:
#         PrimeNList.append(i)

# while True:
#     if IsPrimeNum(n) == True:
#         print(n)
#         break

#     for j in PrimeNList:
#         if n % j == 0:
#             print(j)
#             n = n // j
#             break
