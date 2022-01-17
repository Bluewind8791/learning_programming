# +++ 문제 설명 +++
# 주차장의 요금표와 차량이 들어오고(입차) 나간(출차) 기록이 주어졌을 때, 
# 차량별로 주차 요금을 계산하려고 합니다. 


# 어떤 차량이 입차된 후에 출차된 내역이 없다면, 23:59에 출차된 것으로 간주합니다.
#   00:00부터 23:59까지의 입/출차 내역을 바탕으로 
# 차량별 누적 주차 시간을 계산하여 요금을 일괄로 정산합니다.
# 누적 주차 시간이 기본 시간이하라면, 기본 요금을 청구합니다.
# 누적 주차 시간이 기본 시간을 초과하면, 기본 요금에 더해서, 
#   초과한 시간에 대해서 단위 시간 마다 단위 요금을 청구합니다.
#   초과한 시간이 단위 시간으로 나누어 떨어지지 않으면, 올림합니다.

# 주차 요금을 나타내는 정수 배열 fees, 
# 자동차의 입/출차 내역을 나타내는 문자열 배열 records가 매개변수로 주어집니다. 

# fees[0] = 기본시간(분)
# fees[1] = 기본 요금(원)
# fees[2] = 단위 시간(분)
# fees[3] = 단위 요금(원)

# records "시각 차량번호 내역" 형식의 문자열
# 시각, 차량번호, 내역은 하나의 공백으로 구분되어 있습니다.
# HH:MM 형식의 길이 5인 문자열
# 차량번호는 자동차를 구분하기 위한, `0'~'9'로 구성된 길이 4인 문자열
# 내역은 길이 2 또는 3인 문자열로, IN 또는 OUT입니다

# 차량 번호가 작은 자동차부터 청구할 주차 요금을 차례대로 
# 정수 배열에 담아서 return 하도록 solution 함수를 완성해주세요.


from datetime import datetime
from collections import Counter


def calculate_fee(fees, time):
    # 기본요금 설정
    fee = fees[1]

    # 기본요금 초과시
    if time > fees[0]:
        extra_fee = (time - fees[0]) // fees[2]
        if (time - fees[0]) % fees[2] != 0:
            extra_fee += 1
        fee += (extra_fee * fees[3])
    # 기본요금 초과 안했으면
    return fee

def calculate_time(start_time, end_time):
    start = datetime.strptime(start_time, "%H:%M")
    end = datetime.strptime(end_time, "%H:%M")

    time = end - start
    # minute 로 환산
    time = int(time.seconds // 60)
    return time


def solution(fees, records):

    # 편의성을 위하여 2차열 배열로 변환
    record_list = []
    for i in range(len(records)):
        record_list.append(records[i].split(" "))


    # in list & out list 분할
    in_list = []
    out_list = []

    for i in range(len(record_list)):
        if record_list[i][2] == "IN":
            in_list.append([record_list[i][1], record_list[i][0]])
        else:
            out_list.append([record_list[i][1], record_list[i][0]])

    in_list = sorted(in_list, key=lambda n: n[0])
    out_list = sorted(out_list, key=lambda n: n[0])


    # Counter class
    fee_list = Counter()

    for i in range(len(in_list)):
        small_result = None

        try:
            # 차량이 출차 되었다면
            if in_list[i][0] == out_list[i][0]:
                small_result = Counter({in_list[i][0]: calculate_time(in_list[i][1], out_list[i][1])})
                fee_list += small_result

            # 차량이 아직 출차 되지 않았다면
            else:
                small_result = Counter({in_list[i][0]: calculate_time(in_list[i][1], "23:59")})
                fee_list += small_result
                # out list에 빈 리스트 삽입으로 인덱스 맞춤
                out_list.insert(i, [])

        except:
            out_list.insert(i, [])
            small_result = Counter({in_list[i][0]: calculate_time(in_list[i][1], "23:59")})
            fee_list += small_result


    # 형변환 및 key(차량번호) 순  정렬
    fee_list.most_common()
    fee_list = sorted(fee_list.items())


    # 요금 계산
    answer = []
    for i in range(len(fee_list)):
        answer.append(calculate_fee(fees ,fee_list[i][1]))
    
    return answer


# test 1
# fees = [180, 5000, 10, 600]
# records = [
#     "05:34 5961 IN", 
#     "06:00 0000 IN", 
#     "06:34 0000 OUT", 
#     "07:59 5961 OUT", 
#     "07:59 0148 IN", 
#     "18:59 0000 IN", 
#     "19:09 0148 OUT", 
#     "22:59 5961 IN", 
#     "23:00 5961 OUT"]

# test 2
# fees = [120, 0, 60, 591]
# records = [
#     "16:00 3961 IN",
#     "16:00 0202 IN",
#     "18:00 3961 OUT",
#     "18:00 0202 OUT",
#     "23:58 3961 IN"]

# test 3
# fees = [1, 461, 1, 10]
# records = ["00:00 1234 IN"]


print(solution([120, 0, 60, 591], [
    "16:00 3961 IN",
    "16:00 0202 IN",
    "18:00 3961 OUT",
    "18:00 0202 OUT",
    "23:58 3961 IN"]))


# correct!!!