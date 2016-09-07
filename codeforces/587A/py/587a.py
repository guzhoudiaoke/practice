import sys

n = int(input())
wn = list(map(int, sys.stdin.readline().split()))

counts = [0] * 1000101
for i in range(n):
    counts[wn[i]] += 1

ans = 0
for i in range(1000100):
    if counts[i] == 0:
        continue

    counts[i+1] += counts[i] >> 1
    if counts[i] & 1 != 0:
        ans += 1

print(ans)
