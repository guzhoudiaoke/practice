import sys

a, b = map(int, sys.stdin.readline().split())
ans = 0
while True:
    if a < b:
        a += 1
        b -= 2
    else:
        a -= 2
        b += 1

    if a >= 0 and b >= 0:
        ans += 1

    if a <= 0 or b <= 0:
        break

print(ans)
