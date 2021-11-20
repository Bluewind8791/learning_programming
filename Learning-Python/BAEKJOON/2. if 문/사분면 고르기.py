x = int(input())
y = int(input())

quad = 0

if x > 0 and y > 0:
    quad = 1
elif x > 0 and y < 0:
    quad = 4
elif x < 0 and y > 0:
    quad = 2
elif x < 0 and y < 0:
    quad = 3


print(quad)
