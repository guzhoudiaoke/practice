import sys

n, x = map(int, sys.stdin.readline().split())

ans = 0
for i in range(n):
    opt, num = sys.stdin.readline().split()
    if opt == '+':
        x += int(num)
    else:
        want = int(num)
        if want > x:
            ans += 1
        else:
            x -= want

print(x, ans)
