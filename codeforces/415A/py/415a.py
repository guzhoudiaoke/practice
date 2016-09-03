import sys

n, m = map(int, sys.stdin.readline().split())
an = list(map(int, sys.stdin.readline().split()))

ans = [0] * n
for i in an:
    for j in range(i-1, n):
        if ans[j] == 0:
            ans[j] = i

print(' '.join(map(str, ans)))
