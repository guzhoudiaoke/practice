import sys

n = int(input())
an = list(map(int, sys.stdin.readline().split()))

ans = 0
while True:
    max_i = 0
    for i in range(1, n):
        if an[i] >= an[max_i]:
            max_i = i

    if max_i is 0:
        break
    else:
        an[0] += 1
        an[max_i] -= 1
        ans += 1

print(ans)
