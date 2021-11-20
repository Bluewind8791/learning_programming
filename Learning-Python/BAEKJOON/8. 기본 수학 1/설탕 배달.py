sugar_kg = int(input())
fiveKG = 0
threeKG = 0

if sugar_kg < 3:
    print(-1)

if sugar_kg % 5 == 0:
    print(sugar_kg // 5)
else:
    fiveKG = sugar_kg // 5
    threeKG = sugar_kg - (fiveKG * 5)
    while True:
        if threeKG % 3 != 0:
            if fiveKG <= 0:
                print(-1)
                break
            fiveKG -= 1
            threeKG += 5
        elif threeKG % 3 == 0:
            threeKG = threeKG // 3
            print(fiveKG + threeKG)
            break
