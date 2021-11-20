# import sys
# input = sys.stdin.readline

formula = input().split("-")

sum = 0
for i in formula[0].split("+"):
    sum += int(i)

for i in formula[1:]:
    temp_sum = 0
    for j in i.split("+"):
        temp_sum += int(j)
    sum -= temp_sum

print(sum)


# 마이너스를 만날 때 가장 큰 수를 빼면 되는 것이다.
# 마이너스 기호를 만날 때 다음 마이너스 까지,
# 다음 마이너스가 없다면 끝까지 모든 수를 더해서 한 번에 빼 주면 문제에서 원하는 답을 얻을 수 있다
