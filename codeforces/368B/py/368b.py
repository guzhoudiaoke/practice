import sys

n, m = map(int, sys.stdin.readline().split())
an = list(map(int, sys.stdin.readline().split()))

counts = [0] * (n)
id = n-1
s = set()
while id >= 0:
    s.add(an[id])
    counts[id] = len(s)
    id -= 1

ans = ""
for i in range(m):
    l = int(input())
    ans += str(counts[l-1])
    if i != m - 1:
        ans += "\n"

print(ans)
