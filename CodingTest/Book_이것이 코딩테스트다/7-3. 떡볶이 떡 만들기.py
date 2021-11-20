# 길이가 일정하지 않은 떡을 절단기에 넣어 일정한 크기로 자르고 남은 떡을 판다
# 손님이 요청한 길이가 m일때, 적어도 m만큼의 떡을 얻기위해 절단기에 설정할 수 있는 높이의 최댓값은?

# +++ input +++

# 떡의 개수 n과 요청한 떡의 길이 m (1 <= n <= 1,000,000 , 1 <= m <= 2,000,000,000)
# n, m = map(int, input().split())
# dduk = list(map(int, input().split()))

n = 4
m = 6
dduk = [19, 15, 10, 17]


# 이진 탐색 문제이자, 파라메트릭 서치 문제 (Parametric Search)
# parametric search는 최적화 문제를 결정 문제로 바꾸어 해결하는 기법
# '원하는 조건을 만족하는 가장 알맞은 값을 찾는 문제'에 사용

# logic: h를 반복해서 조정해 가면서 조건을 만족하는지 확인하면서
# 이진 탐색기법으로 탐색하며 범위를 좁혀가면서 해결한다.


def bin_search(target, start, end):
    if start > end:
        return None

    total = 0
    mid = (start + end) // 2

    for d in dduk:
        if d - mid < 1:
            continue
        total += d - mid

    if total == target:
        return mid
    elif total > target:  # right
        return bin_search(target, mid + 1, end)
    else:
        return bin_search(target, start, mid - 1)


result = bin_search(m, 0, max(dduk))
print(result)


# +++ book answer +++

start = 0
end = max(dduk)

# binary search
result = 0
while start <= end:
    total = 0
    mid = (start + end) // 2
    for x in dduk:
        if x > mid:
            total += x - mid
    # 떡 양이 불충분
    if total < m:
        end = mid - 1
    # 떡 양이 충분한 경우 덜 자르기
    else:
        # 최대한 덜 잘랐을떄가 정답이기 때문에, result에 기록
        result = mid
        start = mid + 1

print(result)
