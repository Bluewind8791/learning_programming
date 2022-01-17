# 1. 컴퓨터의 수 (100이하)
# 2. 컴퓨터 쌍의 수


n = 7
m = 6
connect = [[1, 2], [2, 3], [1, 5], [5, 2], [5, 6], [4, 7]]

visited = [False] * 6
result = 0


def dfs(depth):
    global result
    if depth == m:
        return

    for i in range(m):
        if connect[depth][i] >= 1:
            connect[depth][i] == False
            result += 1
            dfs(i)


dfs(0)
print(result)
