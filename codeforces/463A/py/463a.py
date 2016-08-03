import sys

n, s = map(int, sys.stdin.readline().split())

ans = -1
for i in range(n):
    x, y = map(int, sys.stdin.readline().split())
    if x * 100 + y <= s * 100:
        if y == 0:
            ans = max(ans, 0)
        else:
            ans = max(ans, 100 - y)

print(ans)
