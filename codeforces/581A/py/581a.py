import sys

a, b = map(int, sys.stdin.readline().split())
x, y = min(a, b), int(abs(a - b) / 2)
print(x, y, sep=' ')
