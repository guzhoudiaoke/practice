import sys

k = int(input())
an = list(map(int, sys.stdin.readline().split()))
an.sort(reverse=True)

sum = 0
month = 0
for x in an:
    if sum >= k:
        break
    sum += x
    month += 1

if sum >= k:
    print(month)
else:
    print("-1")
