import sys

n, m = map(int, sys.stdin.readline().split())

day = 0
mom = 0
while n > 0:
    day += n
    mom += n
    if mom >= m:
        n = int(mom / m)
        mom -= n*m
    else:
        break

print(day)
