import sys

n = int(input())
percents = list(map(int, sys.stdin.readline().split()))

x = 0
y = 0
for i in range(n):
    x += percents[i]
    y += 1

print("%.10f" % (x / y))
