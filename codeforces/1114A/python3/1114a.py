import sys


def solve(x, y, z, a, b, c):
    if a < x:
        return False
    a -= x
    if a + b < y:
        return False
    if a + b + c - y < z:
        return False

    return True


x, y, z = map(int, sys.stdin.readline().split())
a, b, c = map(int, sys.stdin.readline().split())
ans = solve(x, y, z, a, b, c)
if ans:
    print('YES')
else:
    print('NO')
