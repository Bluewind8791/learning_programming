import sys

input = sys.stdin.readline

lst = []

for _ in range(9):
    lst.append(int(input()))

print(max(lst))
print(1 + lst.index(max(lst)))
