import sys

n = int(input())
an = list(map(int, sys.stdin.readline().split()))

d = {}
ans = 0
for a in an:
    if a not in d:
        d[a] = 1
    else:
        d[a] = d[a] + 1
    ans = max(ans, d[a])
print(ans)
