import sys

n = int(input())
seq = list(map(int, sys.stdin.readline().split()))

m = 1
cur = 1
for i in range(1, n):
    if seq[i] >= seq[i-1]:
        cur += 1
    else:
        cur = 1

    m = max(m, cur)

print(m)
