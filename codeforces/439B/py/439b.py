import sys

n, x = map(int, sys.stdin.readline().split())
cn = list(map(int, sys.stdin.readline().split()))

cn.sort()
ans = 0
for i in range(n):
    ans += x * cn[i]
    if x > 1:
        x -= 1

print(ans)
