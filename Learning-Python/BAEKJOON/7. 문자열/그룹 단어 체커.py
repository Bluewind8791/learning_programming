n = int(input())
group_word_cnt = 0

for _ in range(n):  # n 만큼 문자열 입력 반복
    word = input()  # 문자열 입력받음
    error = 0  # 에러 여부 변수
    for i in range(len(word) - 1):  # 단어안의 알파벳 인덱스 지정
        if word[i] != word[i + 1]:  # 만약 연속된 알파벳이 서로 다른 경우
            new_word = word[i + 1 :]  # 뒤의 부분 새로운 단어로 지정
            if new_word.find(word[i]) > 0:  # 새로운 단어에서 알파벳이 남아있었다면,
                error += 1
    if error == 0:
        group_word_cnt += 1

print(group_word_cnt)
