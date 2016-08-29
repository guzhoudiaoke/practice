import sys

n = int(input())
an = list(map(int, sys.stdin.readline().split()))

ans = []
while True:
    left = 0
    right = 0
    while left + 1 < n and an[left] <= an[left+1]:
        left += 1

    if left + 1 >= n:
        break

    right = left+2
    while right + 1 < n and an[right] >= an[right+1]:
        right += 2

    i = left
    while i+1 < right:
        an[i], an[i+1] = an[i+1], an[i]
        i += 2

    ans.append((left+1, right))

for i in range(len(ans)):
    print(ans[i][0], ans[i][1])
