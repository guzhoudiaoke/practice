import sys

n = int(input())
an = list(map(int, sys.stdin.readline().split()))

mmin = an[0]
imin = 0
mmax = an[0]
imax = 0

for i in range(1, n):
    if an[i] > mmax:
        mmax, imax = an[i], i
    elif an[i] < mmin:
        mmin, imin = an[i], i

big = max(imin, imax)
small = min(imin, imax)

print(max(big-0, n-1-small))
