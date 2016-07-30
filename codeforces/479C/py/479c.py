import sys

n = int(input())
abn = []
for i in range(n):
    a, b = map(int, sys.stdin.readline().split())
    abn.append((a, b))

abn.sort(key=lambda x:(x[0], x[1]))

ans = -1
for i in range(n):
    if ans <= abn[i][1]:
        ans = abn[i][1]
    else:
        ans = abn[i][0]

print(ans)
