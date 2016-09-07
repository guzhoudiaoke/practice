import sys

n, s = map(int, sys.stdin.readline().split())
an = list(map(int, sys.stdin.readline().split()))

ansum = sum(an)
anmax = max(an)

if ansum - anmax <= s:
    print("YES")
else:
    print("NO")
