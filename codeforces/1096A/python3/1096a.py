import sys


t = int(input())
for i in range(t):
    l, r = map(int, sys.stdin.readline().split())
    print(l, l*2)
