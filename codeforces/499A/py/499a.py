import sys

n, x = map(int, sys.stdin.readline().split())

ans = 0
cur = 1
for i in range(n):
    l, r = map(int, sys.stdin.readline().split())
    ans += ((l - cur) % x) + (r - l + 1)
    cur = r + 1

print(ans)
