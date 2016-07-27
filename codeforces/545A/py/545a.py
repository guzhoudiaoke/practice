import sys

n = int(input())
mat = []
ans = []
for i in range(n):
    l = list(map(int, sys.stdin.readline().split()))
    mat.append(l)
    good = True
    for j in range(n):
        if l[j] == 1 or l[j] == 3:
            good = False
    if good:
        ans.append(i+1)

num = len(ans)
print(num)
if num > 0:
    print(' '.join(map(str, ans)))
