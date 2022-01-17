# 두개의 배열 A와 B, 두 배열은 N개의 원소로 이루어져 있으며, 모두 자연수이다.
# 최대 K번의 바꿔치기 연산을 수행할수 있다.
# 목표는 배열 A의 모든 원소의 합이 최대로 만드는것

#  n, k, array a and b 가 주어졌을때
# 최대 k번의 swap을 수행하여 만들수있는 array a의 모든 원소의 합의 최댓값 출력

# +++ input +++
n, k = map(int, input().split())
array_a = list(map(int, input().split()))
array_b = list(map(int, input().split()))

# n = 5
# k = 3
# array_a = [1, 2, 5, 4, 3]
# array_b = [5, 5, 6, 6, 5]

# array a의 가장 작은 값과 array b의 가장 큰 값을 k 번 swap

array_a.sort()
array_b.sort(reverse=True)


# +++ swap +++
for i in range(k):
    # array a의 원소가 b 보다 작으면 swap
    if array_a[i] < array_b[i]:
        array_a[i], array_b[i] = array_b[i], array_a[i]
    else:
        break


print(sum(array_a))
