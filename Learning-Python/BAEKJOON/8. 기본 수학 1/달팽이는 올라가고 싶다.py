## time out ##
# day_climb, sleep_slip, stick_meter = map(int, input().split())
# days = 1

# while True:
#     if day_climb >= stick_meter:  # one day
#         days = 1
#         break
#     days += 1
# if (day_climb * days) - (sleep_slip * (days - 1)) >= stick_meter:  # after two day
#         print(days)
#         break

A, B, V = map(int, input().split())
d = (V - B) / (A - B)

print(int(d) if d == int(d) else int(d) + 1)
