import sys

n, m = map(int, sys.stdin.readline().split())
print(n+m-1)
for i in range(m):
    print(1, i+1)
for i in range(1, n):
    print(i+1, 1)
