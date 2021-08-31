# 각 손님들이 주문한 단품메뉴들이 문자열 형식으로 담긴 배열 orders,
# 코스요리를 구성하는 단품메뉴들의 갯수가 담긴 배열 course가 매개변수로 주어질 때,
# "스카피"가 새로 추가하게 될 코스요리의 메뉴 구성을
# 문자열 형태로 배열에 담아 return 하도록 solution 함수를 완성해 주세요.


def solution(orders, course):
    # orders 배열의 각 원소는 크기가 2 이상 10 이하인 문자열입니다.

    # orders 를 하나하나 쪼개고

    # 정답은 각 코스요리 메뉴의 구성을 문자열 형식으로 배열에 담아 사전 순으로 오름차순 정렬해서 return 해주세요.
    answer = []
    return answer


orders = ["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"]
course = [2, 3, 4]

kindsOfMenu = []

for i in range(0, 1):
    for j in range(len(orders[i])):
        kindsOfMenu.append(orders[i][j])

for i in range(len(orders)):
    for j in range(len(orders[i])):
        if not orders[i][j] in kindsOfMenu:
            kindsOfMenu.append(orders[i][j])

kindsOfMenu.sort()
print(kindsOfMenu)

# kindsOfMenu의 경우의 수 중 course의 가짓수 찾기
# 탐색 알고리즘

# solution(orders, course)
