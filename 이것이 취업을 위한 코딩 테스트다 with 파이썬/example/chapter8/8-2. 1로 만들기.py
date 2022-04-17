# 정수 x가 주어질 때 정수 x에 사용할 수 있는 연산은 4가지

# 1. x가 5로 나누어 떨어지면 5로 나눈다
# 2. 3으로 나누어 떨어지면 3으로 나눈다
# 3. 2로 나누어 떨어지면 2로 나눈다
# 4. x에서 1을 뺀다

# 이 연산 4개를 적절히 사용하여 1을 만들려고 한다
# 최소 수행 값은 얼마인가

# +++ answer +++

# x = int(input())
x = 6

# DP table
d = [0] * 30001

# dynamic programming - bottom-up
for i in range(2, x + 1):
    # 현재 수에서 1을 빼는 경우
    d[i] = d[i - 1] + 1

    # 2로 나누어 떨어지는 경우
    if i // 2 == 0:
        d[i] = min(d[i // 2] + 1, d[i])
    # 3으로 나누어 떨어지는 경우
    if i // 3 == 0:
        d[i] = min(d[i // 3] + 1, d[i])
    # 5로 나누어 떨어지는 경우
    if i // 5 == 0:
        d[i] = min(d[i // 5] + 1, d[i])

print(d[x])

"""
x = 6
# (1 <= x <= 30000)

# DP table
d = [0] * 30001


def makeOne(x):
    result += 1

    if x == 1:
        return result
    
    # 계산했던 문제라면 그대로 return
    if d[x] != 0:
        return d[x]

    if x % 5 == 0:
        d[x] = makeOne(x//5)
    if x % 3 == 0:
        d[x] = makeOne(x//3)
    if x % 2 == 0:
        d[x] = makeOne(x//2)
    d[x] = makeOne(x - 1)

result = 0
makeOne(6)
"""
