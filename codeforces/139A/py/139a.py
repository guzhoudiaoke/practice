import sys

n = int(input())
an = list(map(int, sys.stdin.readline().split()))

total = sum(an)
m = n % total
if m == 0 and n != 0:
    n = total
else:
    n = m

ans = 0
while n > 0 and ans < 7:
    n -= an[ans]
    if n > 0:
        ans += 1
print(1 + ans)
