import sys

n, h = map(int, sys.stdin.readline().split())
an = list(map(int, sys.stdin.readline().split()))

result = 0
for a in an:
    if a > h:
        result += 2
    else:
        result += 1

print(result)
