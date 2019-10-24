import sys


n = int(input())
ans = 0
for i in range(n):
    x, y = map(int, sys.stdin.readline().split())
    ans = max(ans, x + y)

print(ans)
