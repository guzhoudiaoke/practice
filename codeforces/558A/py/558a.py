import sys

n = int(input())
left = []
right = []
for i in range(n):
    x, a = map(int, sys.stdin.readline().split()) 
    if x < 0:
        left.append((x, a))
    else:
        right.append((x, a))

left.sort(key=lambda x:x[0], reverse=True)
right.sort(key=lambda x:x[0])

ans = 0
length = min(len(left), len(right))
for i in range(length):
    ans += left[i][1] + right[i][1]

if len(left) > len(right):
    ans += left[length][1]
elif len(right) > len(left):
    ans += right[length][1]

print(ans)
