def MakeStarList(n):
    if n == 1:
        return ["*"]

    stars = MakeStarList(n // 3)
    starList = []

    for star in stars:
        starList.append(star * 3)
    for star in stars:
        starList.append(star + " " * (n // 3) + star)
    for star in stars:
        starList.append(star * 3)
    return starList


n = int(input())

stars = MakeStarList(n)

print("\n".join(stars))

# for i in stars:
#     for j in i:
#         print(j, end="")
#     print()


###################################### 방식 2 ################################################

# def PrintStars(n):
#     if n == 3:
#         stars[0][:n] = stars[n - 1][:n] = [True] * n
#         stars[1][:n] = [True, False, True]
#         return

#     div3 = n // 3
#     PrintStars(div3)

#     for i in range(3):
#         for j in range(3):
#             if i == 1 and j == 1:
#                 continue
#             for k in range(div3):
#                 stars[div3 * i + k][div3 * j : div3 * (j + 1)] = stars[k][:div3]


# ## main function ##
# # n = int(input())
# n = 9

# global stars
# stars = [[False for _ in range(n)] for _ in range(n)]

# PrintStars(n)

# for i in stars:
#     for j in i:
#         if j == True:
#             print("*", end="")
#         else:
#             print(" ", end="")
#     print()
