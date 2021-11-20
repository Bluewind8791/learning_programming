##---- 단어 공부 ----##

word = input().upper()

list_unique_word = list(set(word))
list_cnt = []

for i in list_unique_word:
    cnt = word.count(i)
    list_cnt.append(cnt)

# list_cnt = [1, 1, 4, 4]
if list_cnt.count(max(list_cnt)) > 1:  # max(list_cnt) = 4
    print("?")
else:
    max_index = list_cnt.index(max(list_cnt))
    print(list_unique_word[max_index])


##---- 문자열 반복 ----##
# repeat = int(input())

# for i in range(repeat):
#     times, string = input().split()
#     times = int(times)
#     for j in string:
#         print(j * times, end="")
#     print()


##---- 알파벳 찾기 ----##
# s = input()
# alphabet = "abcdefghijklmnopqrstuvwxyz"

# for i in alphabet:
#     if i in s:
#         print(s.find(i), end=" ")
#     elif i not in s:
#         print("-1", end=" ")


##---- 숫자의 합 ----##
# n = int(input())
# number = input()
# sum = 0
# for i in range(len(number)):
#     sum += int(number[i])
# print(sum)


##---- 아스키 코드 ----##
# asciicode = input()
# print(ord(asciicode))
