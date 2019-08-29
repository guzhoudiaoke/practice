import sys

t = int(input())
for i in range(t):
    a, b, k = map(int, sys.stdin.readline().split())
    print((k // 2) * (a - b) + (k % 2) * a)
