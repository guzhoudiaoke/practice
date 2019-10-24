import sys


n = int(input())
an = list(map(int, sys.stdin.readline().split()))
an.sort()
print(an[(n-1) // 2])
