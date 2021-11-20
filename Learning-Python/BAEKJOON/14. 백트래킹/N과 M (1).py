n, m = map(int, input().split())

visited = [False] * n
printList = []


def PrintSequence(depth, n, m):
    if depth == m:
        print(" ".join(map(str, printList)))
        return

    for i in range(len(visited)):
        if not visited[i]:  # if not visited
            visited[i] = True  # visited
            printList.append(i + 1)

            PrintSequence(depth + 1, n, m)
            visited[i] = False
            printList.pop()


PrintSequence(0, n, m)
