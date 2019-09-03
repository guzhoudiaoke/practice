import sys

n = int(input())

a, b, c, d = map(int, sys.stdin.readline().split())
s1 = a + b + c + d
rank = 1

for i in range(1, n):
    a, b, c, d = map(int, sys.stdin.readline().split())
    s = a + b + c + d
    if s > s1:
        rank += 1

print(rank)
