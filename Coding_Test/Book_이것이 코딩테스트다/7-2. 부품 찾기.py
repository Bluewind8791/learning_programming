# 전자 매장에 부품 n개가 있으며 고유한 번호가 있다
# 어느날 손님에게서 m개 종류의 부품 대량 구매 요청이 들어왔다.
# m개 부품을 모두 확인하는 프로그램
# 요청한 부품 순서대로 부품을 확인하여 있으면 yes 없으면 no를 출력


# +++ input +++
# n = int(input())
# data = list(map(int, input().split()))
# m = int(input())
# buy = list(map(int, input().split()))

n = 5
data = [8, 3, 7, 9, 2]
m = 3
buy = [5, 7, 9]


print("+++ binary searching 으로 풀어보기 +++")


def bin_search(data, target, start, end):
    if start > end:
        return None

    mid = (start + end) // 2

    if data[mid] == target:
        return mid

    # left
    elif data[mid] > target:
        return bin_search(data, target, start, mid - 1)

    # right
    else:
        return bin_search(data, target, mid + 1, end)


data.sort()

for item in buy:
    if bin_search(data, item, 0, n - 1) == None:
        print("No", end=" ")
    else:
        print("Yes", end=" ")


print("\n\n+++ 계수 정렬로 풀어보기 +++")

# (1 <= n <= 1,000,000)
n = 5
sell = [8, 3, 7, 9, 2]
m = 3
buy = [5, 7, 9]

data = [0] * 1000001

# 부품 기록
for i in sell:
    data[i] += 1

for item in buy:
    if data[item] >= 1:
        print("Yes", end=" ")
    else:
        print("No", end=" ")


print("\n\n+++ 집합 자료형 set()을 사용하여 풀어보기 +++")

n = 5
# array = set(map(int, input().split()))
array = {2, 3, 7, 8, 9}
m = 3
buy = [5, 7, 9]

for i in buy:
    if i in array:
        print("yes", end=" ")
    else:
        print("no", end=" ")
