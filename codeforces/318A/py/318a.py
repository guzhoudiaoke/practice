import sys

n, k = map(int, sys.stdin.readline().split())

mid = int((n + 1) / 2)
if k <= mid:
    print(2 * k - 1)
else:
    print(2 * (k-mid))
