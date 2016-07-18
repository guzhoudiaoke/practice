import sys

a, b = map(int, sys.stdin.readline().split())

hour = 0
wentout = 0
while a > 0:
    hour += a
    wentout += a

    if wentout >= b:
        a = int(wentout / b)
        wentout -= a*b
    else:
        break

print(hour)
