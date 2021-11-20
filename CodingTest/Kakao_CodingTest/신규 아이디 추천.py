# 아이디 규칙에 맞지 않는 아이디를 입력했을 때
# 입력된 아이디와 유사하면서 규칙에 맞는 아이디를 추천해주는 프로그램


import re


def solution(new_id):
    # 1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
    new_id = new_id.lower()

    # 2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
    new_id = re.sub(r"[^a-z0-9-_.]", "", new_id)

    # delThing = list(string.ascii_lowercase)
    # for x in range(0, 10):
    #     delThing.append(str(x))
    # delThing.append("-")
    # delThing.append(".")
    # delThing.append("_")

    # for i in range(len(new_id)):
    #     for j in range(len(delThing)):
    #         if new_id[i] == delThing[j]:
    #             answer.append(delThing[j])
    #             break

    # answer2 = "".join(answer)

    # 3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
    while True:
        new_id = new_id.replace("..", ".")
        if ".." not in new_id:
            break

    # 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
    if new_id.find(".") == 0:
        new_id = new_id.lstrip(".")
    if new_id.rfind(".") == len(new_id) - 1:
        new_id = new_id.rstrip(".")

    # 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
    if new_id == "":
        return "aaa"

    # 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
    #      만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
    while True:
        if len(new_id) < 16:
            break
        new_id = new_id[:-1]

    if new_id.rfind(".") == len(new_id) - 1:
        new_id = new_id.rstrip(".")

    # 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
    while True:
        if len(new_id) > 2:
            break
        new_id.append(new_id[-1])
    return new_id


new_id = "...!@BaT#*..y.abcdefghijklm"
# new_id = input()
print(solution(new_id))


# 3 9 13 fail


# - sub 메서드
# 정규식과 매칭되면 변경시킨다
# sub 메쏘드는 주어진 string 전체에서 pattern과 일치하는 모든 것을 replace로 교체하고, 결과를 str 타입으로 반환한다.

# python 정규식 []

# <str> = re.sub(pattern, replace, string, count=0, flag=0)
# new_id = re.sub(r"[^a-z0-9-_.]", "", new_id)
# print(new_id)
