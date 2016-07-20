import sys

n = int(input())
colors = [[0, 0]] * n
for i in range(n):
    colors[i] = list(map(int, sys.stdin.readline().split()))

ret = 0
for i in range(n):
    for j in range(n):
        if j != i and colors[i][1] == colors[j][0]:
            ret += 1

print(ret)
