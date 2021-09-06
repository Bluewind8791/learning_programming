import collections
import itertools

def solution(orders, course):
    result = []

    for course_size in course:
        order_combinations = []
        for order in orders:
            order order_combinations += itertools.combinations(sorted(order), course_size)

    
    return order_combinations


solution()