import sys

n, a, b, c = map(int, sys.stdin.readline().split())
an = [a, b, c]

dp = [-1] * (n+1)
dp[0] = 0

for i in range(3):
    for j in range(n - an[i] + 1):
        if dp[j] != -1:
            dp[j + an[i]] = max(dp[j+an[i]], dp[j]+1)

print(dp[n])
