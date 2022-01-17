# 게시판 불량 이용자 신고 및 처리 결과를 메일로 발송하는 시스템

# 각 유저는 한번에 유저 한명 신고 가능, 횟수에 제한은 없음
# 한 유저를 여러번 신고할 수 있지만 동일한 유저에 대한 신고 횟수는 1회로 처리

# k번 이상 신고된 유저는 게시판 이용 정지 및 신고한 모든 유저에게 정지 사실을 메일로 발송
# 게시판 이용이 정지된 유저도 불량 이용자 신고 가능

# 이용자의 Id가 담긴 문자열 배열 id_list
# 각 이용자가 신고한 이용자의 ID 정보가 담긴 문자열 배열 report
# 정지 기준이 되는 신고횟수 k

# 각 유저별로 처리결과 메일을 받은 횟수를 배열에 담아 return 하도록 solution 함수 완성


# 2 ≤ id_list의 길이 ≤ 1,000
#   1 ≤ id_list의 원소 길이 ≤ 10
#   id_list의 원소는 이용자의 id를 나타내는 문자열이며 알파벳 소문자로만 이루어져 있습니다.
#   id_list에는 같은 아이디가 중복해서 들어있지 않습니다.

# 1 ≤ report의 길이 ≤ 200,000
#   3 ≤ report의 원소 길이 ≤ 21
#   report의 원소는 "이용자id 신고한id"형태의 문자열입니다.
#   예를 들어 "muzi frodo"의 경우 "muzi"가 "frodo"를 신고했다는 의미입니다.
#   id는 알파벳 소문자로만 이루어져 있습니다.
#   이용자id와 신고한id는 공백(스페이스)하나로 구분되어 있습니다.
#   자기 자신을 신고하는 경우는 없습니다.

# 1 ≤ k ≤ 200, k는 자연수입니다.
# return 하는 배열은 id_list에 담긴 id 순서대로 각 유저가 받은 결과 메일 수를 담으면 됩니다.

import collections


id_list = ["muzi", "frodo", "apeach", "neo"]
report = ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"]
k = 2


# 동일한 유저에 대한 신고 횟수는 1회로 처리 > report 중복 제거
report = set(report)
report = list(report)

# block 당한 유저 찾기
block_list = []
split_report = []

for i in range(len(report)):
    split_report.append(report[i].split(" "))
    block_list.append(report[i].split(" "))
    del block_list[i][0]

print(split_report)
block_list = sum(block_list, [])
print(block_list)

counting = collections.Counter(block_list).most_common()
print(counting)

block_list = []
for i in range(len(counting)):
    if counting[i][1] >= 2:
        block_list.append(counting[i][0])
print(block_list)


# block 유저를 신고한 유저를 찾아 메일 발송 수 배열 생성

# 메일 발송 수 배열 생성
send_mail = [0] * len(id_list)

# id list 중 report[0] 가 동일한 인덱스 중 report[1]가 block list 안에 있다면 count 1 추가
for i in range(len(id_list)):
    for j in range(len(split_report)):
        if id_list[i] == split_report[j][0]:
            for k in block_list:
                if split_report[j][1] == k:
                    send_mail[i] += 1

print(send_mail)





def solution(id_list, report, k):
    # 동일한 유저에 대한 신고 횟수는 1회로 처리 > report 중복 제거
    report = set(report)
    report = list(report)

    # block 당한 유저 찾기
    block_list = []
    split_report = []

    for i in range(len(report)):
        split_report.append(report[i].split(" "))
        block_list.append(report[i].split(" "))
        del block_list[i][0]

    block_list = sum(block_list, [])

    counting = collections.Counter(block_list).most_common()

    block_list = []

    for i in range(len(counting)):
        if counting[i][1] >= 2:
            block_list.append(counting[i][0])


    # block 유저를 신고한 유저를 찾아 메일 발송 수 배열 생성

    # 메일 발송 수 배열 생성
    answer = [0] * len(id_list)

    # id list 중 report[0] 가 동일한 인덱스 중 report[1]가 block list 안에 있다면 count 1 추가
    for i in range(len(id_list)):
        for j in range(len(split_report)):
            if id_list[i] == split_report[j][0]:
                for k in block_list:
                    if split_report[j][1] == k:
                        answer[i] += 1
                        
    return answer



""" ex 1
id_list = ["muzi", "frodo", "apeach", "neo"]
report = ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"]
k = 2
"""


""" ex 2
id_list = ["con", "ryan"]	
report = ["ryan con", "ryan con", "ryan con", "ryan con"]
k = 3
"""


# print(solution(["muzi", "frodo", "apeach", "neo"], ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"], 2))