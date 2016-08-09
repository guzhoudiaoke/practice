import sys

n, d = map(int, sys.stdin.readline().split())
friends = []
for i in range(n):
    m, s = map(int, sys.stdin.readline().split())
    friends.append((m, s))

friends.sort(key = lambda x:x[0])
left = 0
right = 0
ans = 0
cur = 0
while left < n:
    while right < n and friends[right][0] - friends[left][0] < d:
        cur += friends[right][1]
        right += 1
    if cur > ans:
        ans = cur

    cur -= friends[left][1]
    left += 1

print(ans)
