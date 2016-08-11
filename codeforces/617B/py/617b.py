import sys

n = int(input())
an = list(map(int, sys.stdin.readline().split()))

ans = 0
pre = 0
for i in range(n):
    if an[i] is 1:
        if ans is 0:
            ans = 1
        else:
            ans *= (i - pre)
        pre = i

print(ans)
