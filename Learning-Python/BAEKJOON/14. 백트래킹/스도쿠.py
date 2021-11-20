import sys

input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

sudoku = [list(map(int, input().split())) for _ in range(9)]
blanks = [(i, j) for i in range(9) for j in range(9) if sudoku[i][j] == 0]


def PromisingNum(i, j):
    AnswerList = [x for x in range(1, 10)]

    for k in range(9):
        if sudoku[i][k] in AnswerList:  # 행 검사하여 동일한 숫자가 있으면 리스트에서 삭제
            AnswerList.remove(sudoku[i][k])
        if sudoku[k][j] in AnswerList:  # 열 검사
            AnswerList.remove(sudoku[k][j])

    if len(AnswerList) > 1:
        # 3x3 검사
        i = i // 3
        j = j // 3
        for y in range(i * 3, (i + 1) * 3):
            for x in range(j * 3, (j + 1) * 3):
                if sudoku[y][x] in AnswerList:
                    AnswerList.remove(sudoku[y][x])

    return AnswerList


def Sudoku(n):
    global isComplete

    if isComplete:
        return

    if n == len(blanks):  # 빈칸의 인덱스가 빈칸의 개수만큼이나 올라오면
        isComplete = True
        for row in sudoku:  # 출력 한 후 종료
            print(*row)
        return

    else:
        (i, j) = blanks[n]  # n 번째 빈칸의 값을 대입
        promisList = PromisingNum(i, j)  # 유망한 답 리스트를 받음

        for num in promisList:
            sudoku[i][j] = num  # 첫번째 유망한 답을 넣어줌
            Sudoku(n + 1)  # 다음 인덱스로 넘어감
            sudoku[i][j] = 0  # 답이 없을 경우 0으로 초기화?


isComplete = False
Sudoku(0)  # n = 빈칸의 index
