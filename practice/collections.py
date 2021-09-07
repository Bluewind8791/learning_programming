import collections

# Counter 편리하고 빠르게 개수를 세도록 지원하는 계수기 도구가 제공됩니다. 예를 들면:

cnt = collections.Counter()
for word in ["red", "blue", "red", "green", "blue", "blue"]:
    cnt[word] += 1

print(cnt)
# Counter({'blue': 3, 'red': 2, 'green': 1})


combination = ["red", "blue", "red", "green", "blue", "blue"]
counting = collections.Counter(combination)


print(counting)
# Counter({'blue': 3, 'red': 2, 'green': 1})


counting = collections.Counter(combination).most_common()
print(counting)
# most_common() 모듈을 사용하여 형변환
# [('blue', 3), ('red', 2), ('green', 1)]
