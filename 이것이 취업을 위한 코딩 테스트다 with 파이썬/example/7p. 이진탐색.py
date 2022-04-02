# 이진 탐색 Binary Search
# 배열 내부의 데이터가 정렬되어있어야 사용할 수 있음

# 변수 3개를 사용 > 시작점, 끝점, 중간점
# 찾으려는 데이터와 중간점 위치에있는 데이터를 반복적으로 비교하여 탐색

# 시간 복잡도는 O(logN)


# recursive Binary Search


def binary_search(array, target, start, end):
    if start > end:
        return None

    mid = (start + end) // 2

    # 중간점 값이 타겟이였다면 중간점 인덱스 반환
    if array[mid] == target:
        return mid

    # 타겟이 중간보다 왼쪽에 있다면
    elif array[mid] > target:
        return binary_search(array, target, start, mid - 1)

    # 타겟이 중간보다 오른쪽에 있다면
    elif array[mid] < target:
        return binary_search(array, target, mid + 1, end)


n, target = list(map(int, input().split()))
array = list(map(int, input().split()))

result = binary_search(array, target, 0, n - 1)

if result == None:
    print("There is no data")
else:
    print(f"The target's index is {result + 1}")


# +++ Using 'for' method +++


def bin_search(array, target, start, end):
    while start <= end:
        mid = (start + end) // 2

        if array[mid] == target:
            return mid
        elif array[mid] > target:
            end = mid - 1
        else:
            start = mid + 1
    return None
