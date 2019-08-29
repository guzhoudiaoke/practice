import sys


n, m = map(int, sys.stdin.readline().split())
points = [0 for i in range(m + 1)]
for i in range(n):
    l, r = map(int, sys.stdin.readline().split())
    for j in range(l, r+1):
        points[j] = 1

ans = []
for i in range(1, m+1):
    if points[i] == 0:
        ans += [i]

print(len(ans))
if len(ans) > 0:
    print(' '.join(str(a) for a in ans))
