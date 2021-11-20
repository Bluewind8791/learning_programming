# 수 정렬하기2 (merge sort)


def Merge_sort(arr):
    # 쪼개는 과정
    if len(arr) <= 1:  # 배열의 원소 갯수가 1개이하인 경우
        return arr

    middle = len(arr) // 2
    leftArr = arr[:middle]  # 앞 부분 배열을 1개씩 될 때까지 쪼갬
    rightArr = arr[middle:]  # 뒷 부분 배열을 1개씩 될 때까지 쪼갬
    leftArr = Merge_sort(leftArr)
    rightArr = Merge_sort(rightArr)

    return Merge(leftArr, rightArr)


def Merge(left, right):
    merged_arr = []
    while len(left) > 0 or len(right) > 0:
        if len(left) > 0 and len(right) > 0:
            if left[0] <= right[0]:
                merged_arr.append(left[0])
                left = left[1:]
            elif right[0] <= left[0]:
                merged_arr.append(right[0])
                right = right[1:]
        elif len(left) > 0:
            merged_arr.append(left[0])
            left = left[1:]
        elif len(right) > 0:
            merged_arr.append(right[0])
            right = right[1:]
    return merged_arr


n = int(input())
arr = []
for _ in range(n):
    arr.append(int(input()))

sorted = Merge_sort(arr)

for i in Merge_sort(sorted):
    print(i)
