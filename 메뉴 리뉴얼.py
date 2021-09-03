# 각 손님들이 주문한 단품메뉴들이 문자열 형식으로 담긴 배열 orders,
# 코스요리를 구성하는 단품메뉴들의 갯수가 담긴 배열 course가 매개변수로 주어질 때,
# "스카피"가 새로 추가하게 될 코스요리의 메뉴 구성을
# 문자열 형태로 배열에 담아 return 하도록 solution 함수를 완성해 주세요.
# orders 배열의 각 원소는 크기가 2 이상 10 이하인 문자열입니다.


def solution(orders, course):
    answer = []
    return answer


##################################################################################################

orders = ["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"]
course = [2, 3, 4]

# 메뉴의 총 가짓수를 찾아서 배열에 집어넣기
kindsOfMenu = []

for ordered in range(0, 1):
    for j in range(len(orders[ordered])):
        kindsOfMenu.append(orders[ordered][j])

for ordered in range(len(orders)):
    for j in range(len(orders[ordered])):
        if not orders[ordered][j] in kindsOfMenu:
            kindsOfMenu.append(orders[ordered][j])

kindsOfMenu.sort()  # ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H']


# 탐색 알고리즘을 사용하여 kindsOfMenu의 경우의 수 중 코스 요리의 가짓수 찾기
printList = []
courseList = []
visited = [False] * len(kindsOfMenu)


def dfs(depth, courseList, m):
    if depth == m:
        courseList.append(tuple(printList))
        return

    for i in range(len(kindsOfMenu)):  # 0~7
        if not visited[i]:
            visited[i] = True
            printList.append(kindsOfMenu[i])
            dfs(depth + 1, courseList, m)
            visited[i] = False
            printList.pop()


for item in course:
    dfs(0, courseList, item)


courseList = [list(item) for item in courseList]  # tuple을 list 화 시키기
courseList = [sorted(item) for item in courseList]  # list를 정렬하고
courseList = [tuple(item) for item in courseList]  # 다시 tuple화 시키고
courseList = set(courseList)  # set 함수로 중복된 값을 삭제
courseList = [list(item) for item in courseList]  # 다시 list화 시키고 sorting
courseList.sort()

# list를 join으로 합쳐서 1차원 함수로 변경
courseList2 = ["".join(item) for item in courseList]


# orders = ["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"]

# print(courseList2)
# ['AB', 'ABC', 'ABCD', 'ABCE', 'ABCF', 'ABCG', 'ABCH', 'ABD', 'ABDE', 'ABDF', 'ABDG', 'ABDH', 'ABE', 'ABEF', 'ABEG', 'ABEH',
# 'ABF', 'ABFG', 'ABFH', 'ABG', 'ABGH', 'ABH', 'AC', 'ACD', 'ACDE', 'ACDF', 'ACDG', 'ACDH',
# 'ACE', 'ACEF', 'ACEG', 'ACEH', 'ACF', 'ACFG', 'ACFH', 'ACG', 'ACGH', 'ACH', 'AD', 'ADE', 'ADEF', 'ADEG', 'ADEH', 'ADF',
# 'ADFG', 'ADFH', 'ADG', 'ADGH', 'ADH', 'AE', 'AEF', 'AEFG', 'AEFH', 'AEG', 'AEGH', 'AEH', 'AF', 'AFG', 'AFGH', 'AFH', 'AG',
# 'AGH', 'AH', 'BC', 'BCD', 'BCDE', 'BCDF', 'BCDG', 'BCDH', 'BCE', 'BCEF', 'BCEG', 'BCEH', 'BCF', 'BCFG', 'BCFH', 'BCG', 'BCGH',
# 'BCH', 'BD', 'BDE', 'BDEF', 'BDEG', 'BDEH', 'BDF', 'BDFG', 'BDFH', 'BDG', 'BDGH', 'BDH', 'BE', 'BEF', 'BEFG', 'BEFH', 'BEG',
# 'BEGH', 'BEH', 'BF', 'BFG', 'BFGH', 'BFH', 'BG', 'BGH', 'BH', 'CD', 'CDE', 'CDEF', 'CDEG', 'CDEH', 'CDF', 'CDFG', 'CDFH', 'CDG',
# 'CDGH', 'CDH', 'CE', 'CEF', 'CEFG', 'CEFH', 'CEG', 'CEGH', 'CEH', 'CF', 'CFG', 'CFGH', 'CFH', 'CG', 'CGH', 'CH', 'DE', 'DEF', 'DEFG',
# 'DEFH', 'DEG', 'DEGH', 'DEH', 'DF', 'DFG', 'DFGH', 'DFH', 'DG', 'DGH', 'DH', 'EF', 'EFG', 'EFGH',
# 'EFH', 'EG', 'EGH', 'EH', 'FG', 'FGH', 'FH', 'GH']

# courseList와 orders 리스트 비교하여 조건에 맞으면 result 리스트에 추가
result = []
for ordered in orders:
    cnt = 0
    for course in courseList2:
        if ordered in course:  # order된 메뉴가 코스리스트에
            cnt += 1
            if cnt == 2:
                result.append(ordered)


print(result)


# solution(orders, course)
