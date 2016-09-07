import sys

n, h, k = map(int, sys.stdin.readline().split())
an = list(map(int, sys.stdin.readline().split()))

ans = 0
cur = 0
height = 0
while cur < n:
    if height + an[cur] <= h:
        height += an[cur]
    else:
        ans += 1
        height = an[cur]

    ans += height // k
    height %= k

    cur += 1
    if cur == n and height != 0:
        ans += 1

print(ans)
