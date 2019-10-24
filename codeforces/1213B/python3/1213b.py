import sys


t = int(input())
for i in range(t):
    n = int(input())
    an = list(map(int, sys.stdin.readline().split()))
    m = an[-1]
    ans = 0
    for j in range(n-1, -1, -1):
        if an[j] > m:
            ans += 1
        else:
            m = an[j]

    print(ans)

