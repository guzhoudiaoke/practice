import sys

def solve(n, an):
    ans = 0
    got = 0
    while True:
        for i in range(n):
            if an[i] <= got:
                an[i] = n+1
                got += 1
        if got == n:
            break
        ans += 1

        i = n-1
        while i >= 0:
            if an[i] <= got:
                an[i] = n+1
                got += 1
            i -= 1
        if got == n:
            break
        ans += 1
    return ans


n = int(input())
an = list(map(int, sys.stdin.readline().split()))
print(solve(n, an))
