import sys

mn = list(map(int, sys.stdin.readline().split()))
wn = list(map(int, sys.stdin.readline().split()))
hs, hu = map(int, sys.stdin.readline().split())
xn = [1, 2, 3, 4, 5]

ans = 0
for i in range(5):
    ans += max(150*xn[i], 500*xn[i] - 2*mn[i]*xn[i] - 50*wn[i])

ans += hs*100 - hu*50
print(ans)
