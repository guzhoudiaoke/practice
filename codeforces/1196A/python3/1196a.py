import sys

def solve(l):
    d1 = l[1] - l[0]
    d2 = l[2] - l[1]
    if d1 < d2:
        return l[1] + (l[2] - d1) // 2
    else:
        return l[2] + (l[0] - d2) // 2


q = int(input())
for i in range(q):
    a, b, c = map(int, sys.stdin.readline().split())
    l = [a, b, c]
    l.sort()
    ans = solve(l)
    print(ans)
