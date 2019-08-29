import sys

n = int(input())
for i in range(n):
    l1, r1, l2, r2 = map(int, sys.stdin.readline().split())
    a = l1
    b = l2
    if b == a:
        b = r2
    print(a, b)
