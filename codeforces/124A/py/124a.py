import sys

n, a, b = map(int, sys.stdin.readline().split())
mmin = max(a, n - b - 1)
if a > n:
    print(0)
else:
    print(n - mmin)
