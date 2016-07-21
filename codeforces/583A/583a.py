import sys

n = int(input())
hn = [0] * (n+1)
vn = [0] * (n+1)

result = []
for i in range(1, n*n+1):
    h, v = map(int, sys.stdin.readline().split())
    if hn[h] == 0 and vn[v] == 0:
        result.append(i)
        hn[h] = 1
        vn[v] = 1

print(" ".join(str(i) for i in result))
