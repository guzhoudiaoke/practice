import sys

n = int(input())
an = list(map(int, sys.stdin.readline().split()))

ans = True
for i in range(n):
    while an[i] % 2 == 0:
        an[i] = int(an[i] / 2)
    while an[i] % 3 == 0:
        an[i] = int(an[i] / 3)

    if i != 0 and an[i] != an[0]:
        ans = False
        break

if ans:
    print("Yes")
else:
    print("No")
