import sys


t = int(input())

for _ in range(t):
    b, p, f = map(int, sys.stdin.readline().split())
    h, c = map(int, sys.stdin.readline().split())

    if h >= c:
        num_h = min(b//2, p)
        num_c = min((b - 2*num_h) // 2, f)
        print(num_h*h + num_c*c)
    else:
        num_c = min(b//2, f)
        num_h = min((b - 2*num_c) // 2, p)
        print(num_h*h + num_c*c)
