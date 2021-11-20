for _ in range(int(input())):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    dist = ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** (1 / 2)  # 두 중심점 사이의 거리
    lst = [r1, r2]
    r_long = max(lst)
    lst.remove(r_long)
    print(
        -1
        if (dist == 0 and r1 == r2)
        else 1  # 두 원이 일치하는 경우
        if (dist == r1 + r2 or r1 == r2 + dist or r2 == r1 + dist)
        else 0  # 두 원이 겹치는 점이 한 개 일 때
        if (
            (dist == 0 and r1 != r2)
            or (dist > r1 + r2)  # 두 원의 중심점은 같으나 길이가 다를 때
            or (r_long > lst[0] + dist)  # 두 원이 떨어져있는 경우
        )
        else 2  # 한 원이 한 원 안에 포함 되어 있을 때
    )
