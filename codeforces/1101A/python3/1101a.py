import sys


q = int(input())
for i in range(q):
    l, r, d = map(int, sys.stdin.readline().split())

    ans = 0
    if l > d:
        ans = d
    else:
        ans = r + d - r%d

    print(ans)
