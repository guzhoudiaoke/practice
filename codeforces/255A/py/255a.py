import sys

n = int(input())
an = list(map(int, sys.stdin.readline().split()))

counts = [0, 0, 0]
for i in range(n):
    counts[i % 3] += an[i]

imax = 0
nmax = counts[0]
for i in range(1, 3):
    if counts[i] > nmax:
        imax = i
        nmax = counts[i]

types = ['chest', 'biceps', 'back']
print(types[imax])
