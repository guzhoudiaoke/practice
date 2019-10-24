import sys


n = int(input())
an = list(map(int, sys.stdin.readline().split()))
an.sort()
print(min(an[n-2] - an[0], an[n-1] - an[1]))
