import sys

n = int(input())
num = 0
for i in range(n):
    p, q = map(int, sys.stdin.readline().split())
    if q - p >= 2:
        num += 1
print(num)
