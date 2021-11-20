n = int(input())

for _ in range(n):
    floor = int(input())
    num = int(input())
    f = [x for x in range(1, num + 1)]  # 0 floor
    for _ in range(floor):
        for i in range(1, num):
            f[i] += f[i - 1]
        # print(f)
    print(f[-1])  # print last list
