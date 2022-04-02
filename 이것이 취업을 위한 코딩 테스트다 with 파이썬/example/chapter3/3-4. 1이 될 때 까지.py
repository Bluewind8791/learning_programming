import time

# 어떠한 수 N이 1이 될 때 까지
# 다음의 두 과정 중 하나를 반복적으로 선택하여 수행
# 단 두번쨰 연산은 n이 k로 나누어 떨어질때만 사용 가능
# 1. n =- 1
# 2. n / k
# 과정을 수행하는 최소 횟수는?

# logic : 나누기를 최대한 많이 해야 함

n = 25
k = 3

result = 0

start_time = time.time()  # start clocking

while True:
    # n이 k 보다 작아지면 break
    if n < k:
        break

    # n이 k에 나누어 떨어지면 k로 나누고
    if n % k == 0:
        n /= k
        result += 1
    else:  # 나누어 떨어지지 않으면 -1을 수행
        n -= 1
        result += 1

while True:
    if n == 1:
        break
    n -= 1
    result += 1

end_time = time.time()  # end clocking
print(result)
print(f"Working Time: {end_time - start_time}")
