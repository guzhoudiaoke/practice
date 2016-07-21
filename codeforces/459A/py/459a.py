import sys

x1, y1, x2, y2 = map(int, sys.stdin.readline().split())

if abs(x1-x2) == 0:
    d = abs(y1-y2)
    print(x1+d, y1, x1+d, y2, sep=' ')
elif abs(y1-y2) == 0:
    d = abs(x1-x2)
    print(x1, y1+d, x2, y2+d, sep=' ')
elif abs(x1-x2) == abs(y1-y2):
    print(x1, y2, x2, y1, sep=' ')
else:
    print("-1")
