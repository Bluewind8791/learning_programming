def Compare(arr):
    for i in range(2):
        for j in range(1, 3):
            if i + j == 3:
                break
            if arr[i] == arr[i + j]:
                arr[i] = False
                arr[i + j] = False
                return [i for i in arr if i != False]
    return [i for i in arr if i != False]


x = [0 for _ in range(3)]
y = [0 for _ in range(3)]

for i in range(3):
    x[i], y[i] = map(int, input().split())

forthX = Compare(x)
forthY = Compare(y)
print(forthX[0], forthY[0])
