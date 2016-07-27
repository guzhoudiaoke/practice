import sys

n, m = map(int, sys.stdin.readline().split())

ans = 0
for i in range(n+1):
    leftm = m - 2*i
    if leftm < 0:
        break

    cur = i
    leftn = n - i
    ans = max(ans, i + min(leftm, int(leftn/2)))

print(ans)
