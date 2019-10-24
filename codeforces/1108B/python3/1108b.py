import sys


n = int(input())
dn = list(map(int, sys.stdin.readline().split()))
x = max(dn)
y = 0
d = {}
for a in dn:
    if a not in d:
        d[a] = 1
    else:
        d[a] += 1

for a in set(dn):
    if x % a == 0:
        d[a] -= 1

y = 0
for k, v in d.items():
    if v > 0 and k > y:
        y = k

print(x, y)
