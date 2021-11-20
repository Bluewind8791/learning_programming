prtList = []


def BackTracking(depth, n, m):
    if depth == m:
        print(" ".join(map(str, prtList)))
        return

    for i in range(n):
        if len(prtList) != 0:  # list가 비어있지 않을 때.
            if prtList[-1] > i + 1:  # 마지막 인덱스의 값이 다음에 들어갈 인덱스보다 크다면 print 하지 않음
                continue
        prtList.append(i + 1)  # 출력 값 append

        BackTracking(depth + 1, n, m)  # 아래로 탐사

        prtList.pop()  # 탐사 완료 후


n, m = map(int, input().split())
BackTracking(0, n, m)
