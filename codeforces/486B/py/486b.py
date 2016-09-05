import sys

m, n = map(int, sys.stdin.readline().split())
mat = []
ans = []

for i in range(m):
    a = list(map(int, sys.stdin.readline().split()))
    mat.append(a)
    ans.append([1] * n)

for i in range(m):
    for j in range(n):
        if mat[i][j] == 0:
            for k in range(n):
                ans[i][k] = 0
            for k in range(m):
                ans[k][j] = 0

row = [0] * m
col = [0] * n
for i in range(m):
    for j in range(n):
        row[i] |= ans[i][j]

for i in range(n):
    for j in range(m):
        col[i] |= ans[j][i]

has = True
for i in range(m):
    for j in range(n):
        if mat[i][j] != (row[i] | col[j]):
            has = False
            break
    if has == False:
        break

if has == False:
    print("NO")
else:
    print("YES")
    for i in range(m):
        print(' '.join(map(str, ans[i])))
    print()

