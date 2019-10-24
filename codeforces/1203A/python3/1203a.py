import sys


def solve(n, pn):
    if n == 1:
        return 'YES'

    count = 0
    if pn[0] > pn[n-1]:
        count = 1

    for i in range(1, n):
        if pn[i] > pn[i-1]:
            count += 1

    if count == 1 or count == n-1:
        return 'YES'
    else:
        return 'NO'


q = int(input())
for _ in range(q):
    n = int(input())
    pn = list(map(int, sys.stdin.readline().split()))
    print(solve(n, pn))
