import sys

input = sys.stdin.readline

n = int(input())
n_lst = list(map(int, input().split()))

print(min(n_lst), max(n_lst))
