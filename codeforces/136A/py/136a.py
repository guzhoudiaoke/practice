import sys

n = int(input())
l = list(map(int, sys.stdin.readline().split()))

result = [0] * (n)
for i in range(n):
    result[l[i]-1] = str(i+1)

print(' '.join(result))
