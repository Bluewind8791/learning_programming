import sys

input = sys.stdin.readline

x, y, w, h = map(int, input().split())
# 6 2 10 3

# 가장 가까운 축을 찾아야함
dist = {"x_dist": x, "y_dist": y, "w_dist": w - x, "h_dist": h - y}

print(min(dist.values()))
