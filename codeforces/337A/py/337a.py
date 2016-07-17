import sys

n, m = map(int, sys.stdin.readline().split())
f = list(map(int, sys.stdin.readline().split()))
f.sort()

result = sys.maxsize
for i in range(0, m-n+1):
    result = min(result, f[i+n-1] - f[i])

print(result)
