import sys

n, t, c = map(int, sys.stdin.readline().split())
an = list(map(int, sys.stdin.readline().split()))

"""
ans = 0
pre = -1
for i in range(n):
    if an[i] > t:
        cnt = i - pre - 1
        pre = i
        if cnt >= c:
            ans += cnt - c + 1

cnt = n - pre - 1
if cnt >= c:
    ans += cnt - c + 1

print(ans)
"""

ans = 0
pre = -1
for i in range(n+1):
    if i == n or (i < n and an[i] > t):
        cnt = i - pre - 1
        pre = i
        if cnt >= c:
            ans += cnt - c + 1

print(ans)
