import sys

def play(n, m):
    if m == 0 or n == 0:
        return 1
    return play(n-1, m-1) ^ 1

n, m = map(int, sys.stdin.readline().split())
if play(n, m) % 2 == 0:
    print("Akshat")
else:
    print("Malvika")
