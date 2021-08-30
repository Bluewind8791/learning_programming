answer = str("a")
print(answer[-1])

while True:
    if len(answer) > 2:
        break
    answer.append(answer[-1])
