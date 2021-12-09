
height, width = map(int, input().split())
n = int(input())

# board reset
board = [[0] * width for _ in range(height)]



for i in range(n):
    length, dir, x, y = map(int, input().split())
    # board[y][x] = 1
    if(dir == 0):
        for k in range(0, length) :
            board[x-1][y-1+k] = 1
    elif dir == 1 :
        for k in range(0, length) :
            board[x-1+k][y-1] = 1


for i in range(height):
    for j in range(width):
        print(board[i][j], end=" ")
    print()


