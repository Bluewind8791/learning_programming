n, m = map(int, input().split())

visited = [False] * n
prtList = []


def BackTracking(start, depth, n, m):
    if depth == m:
        print(" ".join(map(str, prtList)))
        return

    for i in range(start, n):
        if not visited[i]:
            visited[i] = True  # 탐사 했음 표시
            prtList.append(i + 1)  # 1부터 출력

            BackTracking(i + 1, depth + 1, n, m)  # 아래로 탐사

            # 탐사 완료 후
            visited[i] = False
            prtList.pop()


BackTracking(0, 0, n, m)
