import sys

input = sys.stdin.readline
# sys.setrecursionlimit(10 ** 6)

n = int(input())
array = list(map(int, input().split()))

# + - * //
calc = list(map(int, input().split()))

maximum = -(10 ** 9)
minimum = +(10 ** 9)


def dfsRecursion(depth, result, plus, minus, multiply, divide):
    global maximum, minimum

    if depth == n:
        maximum = max(result, maximum)
        minimum = min(result, minimum)
        return

    if plus:
        dfsRecursion(depth + 1, result + array[depth], plus - 1, minus, multiply, divide)
    if minus:
        dfsRecursion(depth + 1, result - array[depth], plus, minus - 1, multiply, divide)
    if multiply:
        dfsRecursion(depth + 1, result * array[depth], plus, minus, multiply - 1, divide)
    if divide:
        dfsRecursion(depth + 1, int(result / array[depth]), plus, minus, multiply, divide - 1)


dfsRecursion(1, array[0], calc[0], calc[1], calc[2], calc[3])
print(maximum)
print(minimum)
