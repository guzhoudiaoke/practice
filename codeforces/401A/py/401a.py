import sys

n, x = map(int, sys.stdin.readline().split())
an = list(map(int, sys.stdin.readline().split()))
s = abs(sum(an))
ans = int(s / x)
if s % x != 0:
    ans += 1
print(ans)
