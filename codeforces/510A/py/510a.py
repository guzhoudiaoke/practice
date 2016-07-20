import sys

n, m = map(int, sys.stdin.readline().split())
line0 = "#"*m
line1 = "."*(m-1) + "#"
line2 = "#" + "."*(m-1)
k = 0
for i in range(n):
    if i % 2 == 0:
        print(line0)
    elif k % 2 == 0:
        print(line1)
        k += 1
    else:
        print(line2)
        k += 1
