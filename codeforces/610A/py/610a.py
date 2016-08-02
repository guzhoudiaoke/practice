n = int(input())

ans = 0
if n % 2 == 0:
    half = n >> 1
    if half % 2 == 0:
        ans = (half >> 1) - 1
    else:
        ans = (half - 1) >> 1

print(ans)
