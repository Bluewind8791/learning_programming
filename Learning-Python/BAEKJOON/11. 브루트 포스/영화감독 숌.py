n = int(input())

seriesCnt = 0

i = 666
while True:
    if "666" in str(i):
        seriesCnt += 1
        if seriesCnt == n:
            print(i)
            break
    i += 1
