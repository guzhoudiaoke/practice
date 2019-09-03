import sys


n = int(input())
an = list(map(int, sys.stdin.readline().split()))
an.sort()

ans = 0
for i in range(0, n, 2):
    ans += an[i+1] - an[i]

print(ans)
