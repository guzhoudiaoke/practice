import sys

na, nb = map(int, sys.stdin.readline().split())
k, m = map(int, sys.stdin.readline().split())

a = list(map(int, sys.stdin.readline().split()))
b = list(map(int, sys.stdin.readline().split()))

if a[k-1] < b[nb-m]:
    print("YES")
else:
    print("NO")
