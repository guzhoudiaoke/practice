import sys
import math

r, x, y, x1, y1 = map(int, sys.stdin.readline().split())

ans = 0
if x1 == x and y1 == y:
    ans = 0
else:
    d = math.sqrt((x1-x)*(x1-x) + (y1-y)*(y1-y))
    ans = math.ceil(d / 2 / r)

print(ans)
