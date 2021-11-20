def Possible(n, queen, row):  # queen을 놓을 수 있는지 검사
    # y번째 열 안에서 x 번의 행을 검사
    for x in range(row):
        if queen[row] == queen[x] or abs(queen[row] - queen[x]) == row - x:
            return False
    return True


def N_Queen(n, queen, row):
    count = 0

    if row == n:  # row가 n 까지 가면 함수를 마치고 1을 리턴
        return 1

    for col in range(n):
        queen[row] = col  # 2차 배열을 만든다

        if Possible(n, queen, row):  # 퀸을 놓을 수 있다면
            count += N_Queen(n, queen, row + 1)  # count를 더하고 다음 열로 넘어간다

    return count


# 행 = 가로
# 열 = 세로

n = int(input())
row = 0
queen = [0] * n  # row 초기화 >> [0,0,0,0]
print(N_Queen(n, queen, row))


# def N_Queen(n, queen, row):
#     count = 0

#     if row == n:  # row가 n 까지 가면 함수를 마치고 1을 리턴
#         return 1

#     for col in range(n):
#         queen[row] = col  # 2차 배열을 만든다

#         for x in range(row):
#             if queen[row] == queen[x] or abs(queen[row] - queen[x]) == row - x:
#                 break
#         else:
#             count += N_Queen(n, queen, row + 1)  # count를 더하고 다음 열로 넘어간다

#     return count


# n = int(input())

# queen = [0] * n  # row 초기화 >> [0,0,0,0]
# print(N_Queen(n, queen, 0))
