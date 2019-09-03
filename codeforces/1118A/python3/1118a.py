import sys


def solve(n, a, b):
    costa = a * n
    costb = b * (n // 2) + a * (n % 2)
    return min(costa, costb)


q = int(input())
for i in range(q):
    n, a, b = map(int, sys.stdin.readline().split())
    ans = solve(n, a, b)
    print(ans)
