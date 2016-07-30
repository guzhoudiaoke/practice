import sys

n, c = map(int, sys.stdin.readline().split())
xn = list(map(int, sys.stdin.readline().split()))

ans = 0
for i in range(1, n):
    if xn[i-1] - xn[i] > ans:
        ans = xn[i-1] - xn[i]

ans = ans - c
if ans < 0:
    ans = 0

print(ans)
