import sys

n = int(input())
an = list(map(int, sys.stdin.readline().split()))

total = sum(an)
ans = 0
for i in range(1, 6):
    if (total + i) % (n + 1) != 1:
        ans += 1

print(ans)
