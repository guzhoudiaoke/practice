import sys

n = int(input())
ln = list(map(int, sys.stdin.readline().split()))

hn = [0] * (1001)
for l in ln:
    hn[l] += 1

mh = 0
num = 0
for i in range(1001):
    if hn[i] != 0:
        num += 1
        if mh < hn[i]:
            mh = hn[i]

print(mh, num)
