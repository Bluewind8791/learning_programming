fixed_cost, variable_cost, price = map(int, input().split())

if variable_cost >= price:
    print(-1)

else:
    prod_volume = int(fixed_cost / (price - variable_cost) + 1)
    print(prod_volume)


## 시간초과 ##
#  fixed_cost, variable_cost, cost = map(int, input().split())
# prod_volume = 0

# while True:
#     total_cost = fixed_cost + variable_cost * prod_volume
#     total_profit = prod_volume * cost
#     if total_profit > total_cost:
#         print(prod_volume)
#         break
#     else:
#         prod_volume += 1

# if prod_volume <= 0:
#     print("-1")
