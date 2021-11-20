import sys

input = sys.stdin.readline

# 피타고라스의 정리 = 가장 긴 변의 길이^2 == 변1^2 + 변2^2

while True:
    sidelist = list(map(int, input().split()))
    if sidelist == [0, 0, 0]:
        break
    sidelong = max(sidelist)
    sidelist.pop(sidelist.index(max(sidelist)))
    side1 = sidelist[0]
    side2 = sidelist[1]
    if (side1 ** 2) + (side2 ** 2) == (sidelong ** 2):
        print("right")
    else:
        print("wrong")
