n = int(input())
hansu_cnt = 0

for i in range(1, n + 1):
    if i <= 99:
        hansu_cnt += 1
    else:
        number = list(map(int, str(i)))
        if number[0] - number[1] == number[1] - number[2]:
            hansu_cnt += 1

print(hansu_cnt)


# 어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다.
# 등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다.
# N이 주어졌을 때, 1보다 크거나 같고,
# N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오.
