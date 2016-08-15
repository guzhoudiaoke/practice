import sys
import math

a, b = map(int, sys.stdin.readline().split())
n = int(input())
ans = 800.0

for i in range(n):
    x, y, v = map(int, sys.stdin.readline().split())
    cur = math.sqrt((x-a)*(x-a) + (y-b)*(y-b)) / v
    if cur < ans:
        ans = cur

print(ans)
