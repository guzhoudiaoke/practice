import sys

n = int(input())
hn = list(map(int, sys.stdin.readline().split()))

ans = 0
energy = 0
pre = 0
for i in range(0, n):
    delta = pre - hn[i]
    energy += delta

    if energy < 0:
        ans += -energy
        energy = 0

    pre = hn[i]

print(ans)
