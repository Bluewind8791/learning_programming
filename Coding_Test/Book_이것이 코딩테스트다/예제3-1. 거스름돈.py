# 카운터에는 거스름돈으로 사용할 500원 100원 50원 10원 동전이 무한히 존재한다고 가정
# 손님에게 거슬러 줘야할 돈이 N원일 때, 거슬러 줘야할 동전의 최소 갯수를 구하라

# -> 가장 큰 화폐부터 돈을 거슬러준다

n = int(input())

fiveHundred = n // 500
n = n % 500

hundred = n // 100
n = n % 100

fifty = n // 50
n = n % 50

ten = n // 10

print(f"500원 {fiveHundred}개 100원 {hundred}개 50원 {fifty}개 10원 {ten}개")

###########################################################################
# - 모범답안 -

n = 1260
count = 0

coin_types = [500, 100, 50, 10]

for coin in coin_types:
    count += n // coin
    n %= coin

print(count)
