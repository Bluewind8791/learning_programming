import sys

input = sys.stdin.readline

n = int(input())  # 도시의 개수를 나타내는 정수
roadLength = list(map(int, input().split()))  # 인접한 두 도시를 연결하는 도로의 길이
price = list(map(int, input().split()))  # 주유소의 리터당 가격


cost = 0
minPrice = price[0]
distance = 0

for i in range(0, n - 1):
    if price[i] < minPrice:
        minPrice = price[i]
    cost += roadLength[i] * minPrice

print(cost)


############### 58 점 짜리 ########################

# cost = 0
# cheapOilIndex = [0 for _ in range(100000)]

# # 가장 싼 주유소에서 기름 넣고 끝까지 가는게 좋다
# # 맨 끝 도시를 제외하고 가장 싼 주유소 인덱스를 찾고
# cheapOilPrice = min(price[:-2])  # 2
# cheapOilIndex[0] = price.index(cheapOilPrice)  # 1
# # 그 인덱스에서 마지막까지 거리까지의 거리*비용을 추가한 뒤
# cost += cheapOilPrice * sum(roadLength[cheapOilIndex[0] :])  # 8
# if cheapOilIndex[0] == 0:
#     print(cost)
#     exit()


# i = 1
# while True:
#     cheapOilPrice = min(price[: cheapOilIndex[i - 1]])
#     cheapOilIndex[i] = price.index(cheapOilPrice)  # 그 인덱스 앞에서 또 가장 싼 주유소2를 찾고
#     cost += cheapOilPrice * sum(roadLength[cheapOilIndex[i] : cheapOilIndex[i - 1]])  # 가장 싼 주유소2에서 주유소1 까지의 기름을 넣는다
#     if cheapOilIndex[i] == 0:  # 이것을 반복하는데, 인덱스가 0이 될때까지
#         break
#     else:
#         i += 1

# print(cost)
