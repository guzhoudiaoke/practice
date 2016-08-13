import sys

d, l, v1, v2 = map(int, sys.stdin.readline().split())
ans = (l - d) / (v1 + v2)
print(ans)
