N = int(input())
# N = 216

for i in range(10, N):
    digitSum = 0
    digitList = list(str(i))
    for j in range(len(digitList)):
        digitSum += int(digitList[j])
    if i + digitSum == N:
        print(i)
        exit()

print(0)
