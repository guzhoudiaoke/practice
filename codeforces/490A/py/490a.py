import sys

n = int(input())
students = list(map(int, sys.stdin.readline().split()))

arr = [[] for i in range(4)]
for i in range(n):
    arr[students[i]].append(i+1)

g = n
for i in range(1, 4):
    if g > len(arr[i]):
        g = len(arr[i])
print(g)

for i in range(g):
    for j in range(1, 4):
        print(arr[j][i], end=' ')
    print("")
