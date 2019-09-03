import sys


n, m = map(int, sys.stdin.readline().split())
ans = -1
for i in range(n):
    a, b = map(int, sys.stdin.readline().split())
    x = a / b * m
    if ans == -1 or ans > x:
        ans = x

print(ans)
