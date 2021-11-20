# n명의 학생 정보가 있다.
# 학생 정보는 학생의 이름과 성적으로 구분
# 성적이 낮은 수선대로 학생의 이름을 출력

# +++ input +++
n = int(input())

data = []
for _ in range(n):
    input_data = input().split()
    # 문자열, 정수형 형태로 변환하여 저장
    data.append((input_data[0], int(input_data[1])))


# n = 2
# data = [("홍길동", 95), ("이순신", 77)]


# 함수를 key 로 사용
def setting(data):
    return data[1]


data = sorted(data, key=setting)

# lambda를 key로 사용
data = sorted(data, key=lambda student: student[1])

for student in data:
    print(student[0], end=" ")
