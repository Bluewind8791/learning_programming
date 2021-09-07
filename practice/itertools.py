import itertools

# chain()
# 리스트를 한 리스트로 연결한다

letters = ["a", "b", "c", "d", "e"]
booleans = [1, 0, 1, 0, 1]
decimals = [0, 7, 0, 8, 0, 9, 0, 4, 0, 5]

# print(list(itertools.chain(letters, booleans, decimals)))
# ['a', 'b', 'c', 'd', 'e', 1, 0, 1, 0, 1, 0, 7, 0, 8, 0, 9, 0, 4, 0, 5]


# combinations(조합, 길이)
# 각 객채의 조합을 만들어서 반환한다

chars = ["A", "B", "C"]

combination = itertools.combinations(chars, 2)
print(list(combination))
# [('A', 'B'), ('A', 'C'), ('B', 'C')]
