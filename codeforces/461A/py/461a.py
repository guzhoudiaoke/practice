import sys

n = int(input())
an = list(map(int, sys.stdin.readline().split()))

an.sort()
result = 0
for i in range(n):
    result += (1+i) * an[i]
    if i != n-1:
        result += an[i]

print(result)
