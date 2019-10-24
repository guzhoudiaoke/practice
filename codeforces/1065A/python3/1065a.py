import sys


t = int(input())
for _ in range(t):
    s, a, b, c = map(int, sys.stdin.readline().split())

    count = s // c
    ans = count + count // a * b
    print(ans)
