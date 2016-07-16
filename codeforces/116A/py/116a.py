import sys

n = int(input())
m = 0
cur = 0
for i in range(n):
    leave, enter = map(int, sys.stdin.readline().split())
    cur -= leave
    cur += enter
    m = max(m, cur)

print(m)
