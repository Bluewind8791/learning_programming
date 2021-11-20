# 각 손님들이 주문한 단품메뉴들이 문자열 형식으로 담긴 배열 orders,
# 코스요리를 구성하는 단품메뉴들의 갯수가 담긴 배열 course가 매개변수로 주어질 때,
# "스카피"가 새로 추가하게 될 코스요리의 메뉴 구성을
# 문자열 형태로 배열에 담아 return 하도록 solution 함수를 완성해 주세요.
# orders 배열의 각 원소는 크기가 2 이상 10 이하인 문자열입니다.


def dfs(depth, total_depth, kindsOfMenu, printList, courseList, visited):
    if depth == total_depth:
        courseList.append(tuple(printList))
        return

    for i in range(len(kindsOfMenu)):
        if not visited[i]:
            visited[i] = True
            printList.append(kindsOfMenu[i])
            dfs(depth + 1, total_depth, kindsOfMenu, printList, courseList, visited)
            visited[i] = False
            printList.pop()


def solution(orders, course):
    # course 조건에 맞는 코스요리를 배열에 추가
    candidates = []

    for o in orders:
        for i in course:
            if len(o) == i:
                candidates.append(o)

    cand = []

    for i in orders:
        printList = []
        courseList = []
        visited = [False] * len(i)
        for n in course:
            dfs(0, n, list(i), printList, courseList, visited)
        courseList = [list(item) for item in courseList]  # tuple을 list 화 시키기
        courseList = [sorted(item) for item in courseList]  # list를 정렬하고
        courseList = [tuple(item) for item in courseList]  # 다시 tuple화 시키고
        courseList = set(courseList)  # set 함수로 중복된 값을 삭제
        courseList = [list(item) for item in courseList]  # 다시 list화 시키고 sorting
        courseList.sort()
        courseList = ["".join(item) for item in courseList]
        cand.append(courseList)

    cand = sum(cand, [])

    answer = {}

    for i in cand:
        try:
            answer[i] += 1
        except:
            answer[i] = 1

    answer = {key: value for key, value in answer.items() if value >= 2}
    answer = list(answer.keys())

    return answer


print(solution(["ABCD", "ABCD", "ABCD"], [2, 3, 4]))
