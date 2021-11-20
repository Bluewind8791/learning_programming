n = int(input())

line = 0  # 사선 라인 번호
line_max_num = 0  # 라인중에 가장 큰 숫자

while True:
    if n <= line_max_num:  # line에서 가장 큰 숫자가 입력받은 값보다 크다면 루프 탈출
        break
    line += 1  # 라인 1씩 올림
    line_max_num += line  # 가장 큰 숫자는 라인 번호를 더한 값이다

diff = line_max_num - n  # 라인에서 가장 큰값과 입력 받은 값의 차이를 구함

if line % 2 == 0:  # 짝수 라인일때
    bunza = line - diff
    bunmo = 1 + diff
else:  # 홀수 라인일 때
    bunza = 1 + diff
    bunmo = line - diff

print("{0}/{1}".format(bunza, bunmo))
