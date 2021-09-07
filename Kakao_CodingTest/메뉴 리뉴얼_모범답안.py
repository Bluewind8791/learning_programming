import collections
import itertools


def solution(orders, course):
    result = []

    for course_size in course:  # 2 3 4
        order_combinations = []
        for order in orders:  # ABCFG, AC, CDE...
            # 메뉴별로 가능한 모든 조합을 만들어 봅니다 / [('A', 'B', 'C', 'F'), ('A', 'B', 'C', 'G'), ('A', 'B', 'F', 'G'), ('A', 'C', 'F', 'G')...
            order_combinations += itertools.combinations(sorted(order), course_size)

        # collections Counter 사용하여 형 변환 [(('B', 'C', 'F', 'G'), 2), (('A', 'C', 'D', 'E'), 2), (('A', 'B', 'C', 'F'), 1), (('A', 'B', 'C', 'G'), 1),
        most_ordered = collections.Counter(order_combinations).most_common()

        result += [k for k, v in most_ordered if v > 1 and v == most_ordered[0][1]]
        # [('A', 'C'), ('C', 'D', 'E'), ('B', 'C', 'F', 'G'), ('A', 'C', 'D', 'E')]

    return ["".join(v) for v in sorted(result)]


orders = ["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"]
course = [2, 3, 4]
print(solution(orders, course))

# ['AC', 'ACDE', 'BCFG', 'CDE']
