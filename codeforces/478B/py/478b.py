import sys

def calc(n):
    if n == 1:
        return 0
    if n % 2 == 0:
        return (n - 1) * (n >> 1)
    return ((n - 1) >> 1) * n

m, n = map(int, sys.stdin.readline().split())

mmin = 0
left = m
each = int(m / n)
mmin += calc(each + 1) * (m % n)

if each != 0:
    mmin += calc(each) * (n - m%n)

mmax = 0
mmax = calc(m - n + 1)

print(mmin, mmax)
