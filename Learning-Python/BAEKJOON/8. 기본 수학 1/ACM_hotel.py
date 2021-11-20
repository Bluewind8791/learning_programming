import math

n = int(input())
room = 0
room_floor = 0
room_n = 0

for i in range(n):
    height, width, guest = map(int, input().split())
    room_n = guest // height
    room_floor = guest - (height * room_n)
    room_n = math.ceil(guest / height)
    if room_floor == 0:
        room_floor = height
    if room_n < 10:
        print("{0}0{1}".format(room_floor, room_n))
    else:
        print("{0}{1}".format(room_floor, room_n))
