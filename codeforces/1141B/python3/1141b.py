import sys


n = int(input())
an = list(map(int, sys.stdin.readline().split()))

n *= 2
an = an * 2

ans = 0
beg = 0
end = 0

while beg < n:
    while beg < n and an[beg] != 1:
        beg += 1

    if beg >= n:
        break

    end = beg + 1
    while end < n and an[end] == 1:
        end += 1

    if end - beg > ans:
        ans = end - beg

    beg = end

print(ans)
