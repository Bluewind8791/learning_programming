# 다양한 수로 이루어진 배열이 있을 때
# 주어진 수들을 M번 더하여
# 가장 큰 수를 만드는 법칙
# 단 배열의 특정한 인덱스에 해당하는 수가
# 연속해서 K번을 초과하여 더해질 수 없다는 것이 특징


# n, m, k = map(int, input().split())
# array = list(map(int, input().split()))

n = 5
m = 8
k = 3

array = [2, 4, 5, 4, 6]

# 가장 큰 수(first)의 인덱스를 찾아서 K번 더하는데
# 더할 때 마다 M 을 넘는지 체크한 다음
# 다음번째 큰 수(second)의 인덱스를 찾아서 K번 더하고
# first를 K번 더하고 반복

array.sort()
first = array[-1]  # 6
second = array[-2]  # 5


cnt = 0
result = 0

while True:
    for _ in range(k):
        if cnt == m:
            break
        result += first
        cnt += 1

    if cnt == m:
        break
    result += second
    cnt += 1

print(result)


# 수열 6665 가 반복된다 즉 K + 1 의 수열이 반복
# 그렇다면 M // (K + 1) 번 반복되는데
# M // (K + 1) 에다가 K 를 곱하면 가장 큰 수 first를 더하는 횟수가 나온다
# 그리고 M % (K + 1) 나머지 값 또한 더해줘야 한다.

# 그렇다면 가장 큰 수 (first)가 더해지는 횟수는
# (m // (k + 1) * k) + (m % (k + 1))

result2 = 0
result2 += first * ((m // (k + 1) * k) + (m % (k + 1)))
result2 += second * (m // (k + 1))

print(result2)
