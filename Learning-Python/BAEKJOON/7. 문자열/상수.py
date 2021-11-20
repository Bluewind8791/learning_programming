## -- 상수 -- ##
question = input()
question = question[::-1]

rev_question = (question).split()

if rev_question[0] > rev_question[1]:
    print(rev_question[0])
else:
    print(rev_question[1])
