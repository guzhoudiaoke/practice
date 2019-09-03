import sys


n, k = map(int, sys.stdin.readline().split())
an = list(map(int, sys.stdin.readline().split()))
ans = 0

i = 0
while i < n and an[i] <= k:
    i += 1
    ans += 1

j = n-1
while j >= i and an[j] <= k:
    j -= 1
    ans += 1

print(ans)

