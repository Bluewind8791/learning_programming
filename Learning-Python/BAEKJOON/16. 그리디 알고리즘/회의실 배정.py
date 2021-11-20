numOfConf = int(input())
confList = []
for _ in range(numOfConf):
    confList.append(list(map(int, input().split())))

# 끝나는 시간을 기준으로 정렬하고, 끝나는 시간이 같다면 빠르게 시작하는 순서대로 정렬
confList.sort(key=lambda x: (x[1], x[0]))


cnt = 1  # 구하고자 하는 값
endTime = confList[0][1]  # 첫번째 리스트 끝나는 시간 저장

for i in range(1, numOfConf):
    if confList[i][0] >= endTime:  # 만약 시작하는 시간이 끝나는 시간보다 크다면
        cnt += 1
        endTime = confList[i][1]  # 끝나는 시간 업데이트

print(cnt)


## 시간 초과 ##
# ConfirmList = []
# while True:
#     ConfirmList.append(confList[0])  # 첫번째 리스트를 집어넣고
#     endTime = int(confList[0][1])  # 첫번째 리스트 끝나는 시간 저장
#     del confList[0]  # 첫번째 리스트 삭제

#     j = 0
#     while True:
#         if j == len(confList):
#             break
#         if confList[j][0] < endTime:  # 끝나는 시간 전에 시작하는 것들은 삭제
#             del confList[j]
#         else:
#             j += 1

#     if len(confList) == 0:
#         break

# print(len(ConfirmList))
