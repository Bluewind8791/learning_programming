def MovingHanoiTower(start, arrive, n):
    if n == 1:
        print(f"{start} {arrive}")
        return

    # 6 = 1 + 2 + 3
    MovingHanoiTower(start, 6 - start - arrive, n - 1)
    print(f"{start} {arrive}")
    MovingHanoiTower(6 - start - arrive, arrive, n - 1)


n = int(input())
print((2 ** n) - 1)
MovingHanoiTower(1, 3, n)
