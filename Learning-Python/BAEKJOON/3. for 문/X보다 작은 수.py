import sys

input = sys.stdin.readline

n, x = map(int, input().split())

list_a = list(map(int, input().split()))

for i in list_a:
    if i < x:
        print(i, end=" ")
