##--- 다이얼 ---###

dial = list(input())
time = 0

for i in range(len(dial)):
    if dial[i] == "A" or dial[i] == "B" or dial[i] == "C":
        time += 3
    if dial[i] == "D" or dial[i] == "E" or dial[i] == "F":
        time += 4
    if dial[i] == "G" or dial[i] == "H" or dial[i] == "I":
        time += 5
    if dial[i] == "J" or dial[i] == "K" or dial[i] == "L":
        time += 6
    if dial[i] == "M" or dial[i] == "N" or dial[i] == "O":
        time += 7
    if dial[i] == "P" or dial[i] == "Q" or dial[i] == "R" or dial[i] == "S":
        time += 8
    if dial[i] == "T" or dial[i] == "U" or dial[i] == "V":
        time += 9
    if dial[i] == "W" or dial[i] == "X" or dial[i] == "Y" or dial[i] == "Z":
        time += 10

print(time)
