import sys

n, m, k = map(int, sys.stdin.readline().split())
if min(m, k) >= n:
    print('Yes')
else:
    print('No')
