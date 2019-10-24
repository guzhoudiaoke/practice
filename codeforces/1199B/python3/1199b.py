import sys


h, l = map(int, sys.stdin.readline().split())
print((l*l - h*h) / 2 / h)
