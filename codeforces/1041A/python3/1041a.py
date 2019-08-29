import sys

n = int(input())
an = list(map(int, sys.stdin.readline().split()))
print(max(an) - min(an) + 1 - n)
