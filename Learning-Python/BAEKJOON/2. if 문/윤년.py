year = int(input())
leapyear = 0

if year % 400 == 0:
    leapyear = 1
if year % 4 == 0 and year % 100 != 0:
    leapyear = 1

print(leapyear)
