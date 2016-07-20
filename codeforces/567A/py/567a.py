import sys

n = int(input())
pos = list(map(int, sys.stdin.readline().split()))

for i in range(n):
    if i == 0:
        mmin = pos[1]-pos[0]
        mmax = pos[n-1] - pos[0]
    elif i == n-1:
        mmin = pos[n-1]-pos[n-2]
        mmax = abs(pos[n-1] - pos[0])
    else:
        mmin = min(pos[i]-pos[i-1], pos[i+1]-pos[i])
        mmax = max(pos[i]-pos[0], pos[n-1]-pos[i])

    print(mmin, mmax, sep=' ')
