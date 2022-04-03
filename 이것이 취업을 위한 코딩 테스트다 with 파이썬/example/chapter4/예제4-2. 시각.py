# 정수 n이 입력되면 0시 0분 0초부터 n시 59분 59초까지의 모든 시각 중에서
# 3이 하나라도 포함되는 모든 경우의 수를 구하는 프로그램

# input
# n = int(input())
n = 5

hour, minute, sec = 0, 0, 0
cnt = 0

while True:
    if hour == n and minute == 59 and sec == 59:
        break

    sec += 1

    if sec == 60:
        sec = 0
        minute += 1
        if minute == 60:
            minute = 0
            hour += 1

    if "3" in str(sec) + str(minute) + str(hour):
        cnt += 1

print(cnt)

# - 교재 답안 -

# h = int(input())
h = 5
count = 0

for i in range(h + 1):
    for j in range(60):
        for k in range(60):
            if "3" in str(i) + str(j) + str(k):
                count += 1

print(count)
