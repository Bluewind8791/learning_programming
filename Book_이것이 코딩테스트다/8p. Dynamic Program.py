# 8-1. 피보나치 함수

"""
def fibo(x):
    if x == 1 or x == 2:
        return 1
    return fibo(x - 1) + fibo(x - 2)

print(fibo(4))
"""

# 이렇게하면 반복되는 호출이 생기며
# x가 커짐에 따라 엄청나게 많은 연산을 필요로 하기때문에 비효율적

# 다이나믹 프로그래밍의 조건
# 1. 큰 문제를 작은 문제로 나눌 수 있다.
# 2. 작은 문제에서 구한 정답은 그것을 포함하는 큰 문제에서도 동일하다.

# Memoization 메모이제이션 기법
# 다이나믹 프로그래밍 구현 방법 중 한 종류로
# 한번 구한 결과를 메모리 공간에 메모해두고 같은 식을 호출하면
# 메모한 결과를 그대로 가져오는 기법 (caching 이라고도 한다)

# 한번 계산된 결과를 메모이제이션 하기위한 리스트 초기화
"""
d = [0] * 100

def fibo(x):
    if x == 1 or x == 2:
        return 1

    # 계산했던 문제라면 그대로 return
    if d[x] != 0:
        return d[x]

    # 계산하지 않은 문제라면 피보나치 결과 return
    d[x] = fibo(x - 1) + fibo(x - 2)
    return d[x]

print(fibo(99))
"""

# 호출되는 함수 확인

"""
d = [0] * 100

def fibo(x):
    print("fibo(" + str(x) + ")", end=" ")
    if x == 1 or x == 2:
        return 1

    # 계산했던 문제라면 그대로 return
    if d[x] != 0:
        return d[x]

    # 계산하지 않은 문제라면 피보나치 결과 return
    d[x] = fibo(x - 1) + fibo(x - 2)
    return d[x]

print(fibo(6))
"""

# 이처럼 recursive를 이용하여 다이나믹 프로그래밍 소스코드 작성은
# 큰 문제를 해결하기 위하여 작은 문제를 호출하여 Top-down 방식이라 한다

# 반복문을 이용하여 소스코드를 작성하는 경우
# 작은 문제부터 차근차근 답을 도출한다고 하여 Bottom-Up 방식이라 한다.


# +++ Bottom-Up 방식 +++

d = [0] * 100

# 첫번쨰 두번쨰 피보나치 수 정의
d[1] = 1
d[2] = 1
n = 99

for i in range(3, n + 1):
    d[i] = d[i - 1] + d[i - 2]

print(d[n])

# 다이나믹 프로그램의 전형적 형태는 Bottom-Up
# Bottom-Up 에서 사용되는 결과 저장용 리스트 (d[])는 'DP 테이블' 이라하며

# memoization 방식은 top-down 방식에 국한되어 사용
# 메모이제이션은 이전에 계산된 결과를 일시적으로 기록해놓는 넓은 개념
