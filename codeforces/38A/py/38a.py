import sys

n = int(input())
dn = list(map(int, sys.stdin.readline().split()))
a, b = map(int, sys.stdin.readline().split())

ans = 0
for i in range(a-1, b-1):
    ans += dn[i]

print(ans)
