import sys

def sum(a1, an):
    return int((a1 + an) * (an - a1 + 1) / 2)

k, n, w = map(int, sys.stdin.readline().split())
print(max(0, sum(1, w) * k - n))
