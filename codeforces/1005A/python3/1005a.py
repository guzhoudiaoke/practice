import sys

n = int(input())
an = list(map(int, sys.stdin.readline().split()))

ans = []
for i in range(1, n):
    if an[i] == 1:
        ans.append(an[i-1])
ans.append(an[n-1])

print(len(ans))
print(' '.join(str(a) for a in ans))
