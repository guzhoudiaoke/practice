import sys

n, k = map(int, sys.stdin.readline().split())
if (n // k) % 2 == 1:
    print('YES')
else:
    print('NO')
