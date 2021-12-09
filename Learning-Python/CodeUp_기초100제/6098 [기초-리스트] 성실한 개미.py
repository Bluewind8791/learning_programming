
area = []
for i in range(10) :
    area.append(list(map(int, input().split())))

x, y = 1, 1

# 개미집 = 2,2 
# 개미는 오른쪽으로만 이동하며 벽 만나면 아래로 이동

while True:
    if area[y][x] == 0 :      # if empty
        area[y][x] = 9
    elif area[y][x] == 2 :      # if eat
        area[y][x] = 9
        break
    
    if(area[y][x+1] == 1 and area[y+1][x] == 1) :   # blocked
        break

    if area[y][x+1] != 1 :    # right side if not wall
        x += 1
    elif area[y+1][x] != 1 :
        y += 1



for i in range(10) :
    for j in range(10) :
        print(area[i][j], end=" ")
    print()