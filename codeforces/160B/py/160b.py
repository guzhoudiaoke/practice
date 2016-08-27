import sys

n = int(input())
s = input()

left = []
right = []

for i in range(n*2):
    if i < n:
        left.append(int(s[i]))
    else:
        right.append(int(s[i]))

left.sort()
right.sort()

ans = True
for i in range(n):
    if right[i] <= left[i]:
        ans = False
        break

if ans is False:
    ans = True
    for i in range(n):
        if right[i] >= left[i]:
            ans = False
            break

if ans is True:
    print("YES")
else:
    print("NO")
