import sys

l, r = map(int, sys.stdin.readline().split())
if l % 2 is not 0:
    l += 1

if r - l < 2:
    print(-1)
else:
    print(l, l+1, l+2)
