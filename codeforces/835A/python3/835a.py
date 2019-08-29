import sys


def total_time(s, v, t):
    return s*v + 2*t


s, v1, v2, t1, t2 = map(int, sys.stdin.readline().split())
x1 = total_time(s, v1, t1)
x2 = total_time(s, v2, t2)
if x1 == x2:
    print('Friendship')
elif x1 < x2:
    print('First')
else:
    print('Second')

