import sys

n, l = map(int, sys.stdin.readline().split())
a = list(map(int, sys.stdin.readline().split()))
a = sorted(a)

mmax = 0
for i in range(1, len(a)):
    mmax = max(mmax, a[i] - a[i-1])

print("%.10f" % max(mmax/2, max(a[0], l - a[n-1])))
