import sys

def solve(n, m):
    if m % n != 0:
        return -1

    x = m // n
    ans = 0
    while x != 1:
        if x % 3 == 0:
            x = x // 3
            ans += 1
        elif x % 2 == 0:
            x = x // 2
            ans += 1
        else:
            return -1
    return ans


n, m = map(int, sys.stdin.readline().split())
print(solve(n, m))
