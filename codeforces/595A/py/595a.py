import sys
n, m = map(int, sys.stdin.readline().split())
ans = 0

for i in range(n):
    windows = list(map(int, sys.stdin.readline().split()))
    for j in range(m):
        if windows[2*j] == 1 or windows[2*j+1]:
            ans += 1

print(ans)

