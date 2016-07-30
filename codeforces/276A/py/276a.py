import sys

n, k = map(int, sys.stdin.readline().split())

ans = -1000000000
for i in range(n):
    f, t = map(int, sys.stdin.readline().split())
    if t > k:
        joy = f - (t-k)
    else:
        joy = f
    if ans < joy:
        ans = joy

print(ans)
