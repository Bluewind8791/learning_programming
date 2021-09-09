array = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]

# selection sorting
# 시간 복잡도 O(N^)

for i in range(len(array)):
    min_index = i
    for j in range(i + 1, len(array)):
        if array[min_index] > array[j]:
            min_index = j

    # swap
    array[i], array[min_index] = array[min_index], array[i]

print(array)

# insert sorting
# 데이터가 거의 정렬되어 있는 상태라면 매우 빠르게 동작
# 시간 복잡도 O(N^)

array = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]

for i in range(1, len(array)):
    for j in range(i, 0, -1):  # index 1부터 0까지 1씩 감소
        if array[j] < array[j - 1]:  # j가 앞의 숫자보다 작다면
            # 한칸씩 왼쪽으로 이동
            array[j], array[j - 1] = array[j - 1], array[j]
        else:  # 자기보다 작은 데이터를 만나면 가만히 멈춤
            break

print(array)


# quick sorting
#

array = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]


def quick_sort(array, start, end):
    # start가 end와 같다면 함수 종료
    if start >= end:
        return

    pivot = start  # pivot 원소는 첫번째 원소
    left = start + 1  # 시작점 바로 오른쪽의 인덱스
    right = end  # 끝점 인덱스

    while True:
        if left > right:  # left가 right보다 오른쪽으로 가면 반복문 종료
            break

        # left가 끝에 닿을때 까지 && left 값이 pivot 값보다 작거나 같을때 까지 오른쪽으로 이동
        while left <= end and array[left] <= array[pivot]:
            left += 1
        # 오른쪽 인덱스가 처음에 닿고 오른쪽 값이 pivot 값보다 크거나 같을때 까지 왼쪽으로 이동
        while right > start and array[right] >= array[pivot]:
            right -= 1

        if left > right:  # 엇갈렸다면 작은 데이터와 피벗을 교체
            array[right], array[pivot] = array[pivot], array[right]
        else:  # 엇갈리지 않았다면 작은 데이터와 큰 데이터를 교체
            array[left], array[right] = array[right], array[left]

    # 분할 이후 왼쪽 부분과 오른쪽 부분 각각 정렬 수행
    quick_sort(array, start, right - 1)
    quick_sort(array, right + 1, end)


quick_sort(array, 0, len(array) - 1)
print(array)
