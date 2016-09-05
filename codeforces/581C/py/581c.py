import sys

n, k = map(int, sys.stdin.readline().split())
an = list(map(int, sys.stdin.readline().split()))


an.sort(key = lambda x:(9 - x%10))
i = 0
while True:
    process = 0
    for i in range(n):
        x = (10 - an[i] % 10)
        if x > k:
            break

        if an[i] != 100:
            an[i] += x
            k -= x
            process += 1
    if process == 0:
        break

ans = 0
for x in an:
    ans += x // 10

print(ans)
