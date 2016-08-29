import sys

n = int(input())
an = list(map(int, sys.stdin.readline().split()))
count = [[0, n, -1] for i in range(1000001)]

m = 0
for i in range(n):
    x = an[i]
    count[x][0] += 1
    if m < count[x][0]:
        m = count[x][0]
    if i < count[x][1]:
        count[x][1] = i
    if i > count[x][2]:
        count[x][2] = i

l, r = 0, n
for i in range(1000001):
    if count[i][0] == m:
        if r - l > count[i][2] - count[i][1]:
            l, r = count[i][1], count[i][2]

print(l+1, r+1)
