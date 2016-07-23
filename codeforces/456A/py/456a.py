import sys

n = int(input())
l = []
for i in range(n):
    a, b = map(int, sys.stdin.readline().split())
    l.append((a,b))

l.sort(key=lambda x: x[0])

happy = False
for i in range(1, n):
    if l[i][1] < l[i-1][1]:
        happy = True
        break

if happy:
    print("Happy Alex")
else:
    print("Poor Alex")
