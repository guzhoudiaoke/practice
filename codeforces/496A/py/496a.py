import sys

n = int(input())
an = list(map(int, sys.stdin.readline().split()))

m = an[2] - an[0]
for i in range(3, n):
    if an[i] - an[i-2] < m:
        m = an[i] - an[i-2]

ans = m
for i in range(1, n):
    if an[i] - an[i-1] > ans:
        ans = an[i] - an[i-1]

print(ans)
