import sys

tn = list(map(int, sys.stdin.readline().split()))
count = [0] * 101
sum = 0
for t in tn:
    count[t] += 1
    sum += t

id = 100
ans = sum
while id > 0:

    if count[id] >= 3 and sum - id*3 < ans:
        ans = sum - id*3
    elif count[id] >= 2 and sum - id*2 < ans:
        ans = sum - id*2
    id -= 1

print(ans)
