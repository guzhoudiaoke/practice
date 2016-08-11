import sys

n, m = map(int, sys.stdin.readline().split())
an = list(map(int, sys.stdin.readline().split()))

ans = 1
left = 0
for i in range(n):
    if left + an[i] <= m:
        left += an[i]
    else:
        left = an[i]
        ans += 1

print(ans)
