import sys

n = int(input())

ans = "NO"
for i in range(n):
    handle, before, after = sys.stdin.readline().split()
    if int(before) >= 2400 and int(after) > int(before):
        ans = "YES"

print(ans)
