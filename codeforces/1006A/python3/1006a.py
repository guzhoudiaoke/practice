import sys


n = int(input())
bn = list(map(int, sys.stdin.readline().split()))

for i in range(n):
    if bn[i] % 2 == 0:
        bn[i] -= 1

print(' '.join(str(b) for b in bn))
