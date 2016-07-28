import sys

n, m = map(int, sys.stdin.readline().split())

ans = 0
if n == 1:
    ans = 1
elif m*2 < n+1:
    ans = m+1
else:
    ans = m-1

print(ans)
