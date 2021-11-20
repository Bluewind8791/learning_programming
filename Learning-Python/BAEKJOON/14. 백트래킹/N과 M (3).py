n, m = map(int, input().split())

prtList = []


def BackTracking(depth, n, m):
    if depth == m:
        print(" ".join(map(str, prtList)))
        return

    for i in range(n):
        prtList.append(i + 1)  # 1부터 출력

        BackTracking(depth + 1, n, m)  # 아래로 탐사

        # 탐사 완료 후
        prtList.pop()


BackTracking(0, n, m)
