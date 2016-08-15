import sys

an = list(map(int, sys.stdin.readline().split()))
ans = (an[0] + an[1] + an[2])*(an[0] + an[1] + an[2]) - an[0]*an[0] - an[2]*an[2] - an[4] * an[4]
print(ans)
