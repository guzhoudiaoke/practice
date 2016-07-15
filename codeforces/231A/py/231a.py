import sys

n = int(input())

result = 0
for i in range(n):
    a, b, c = map(int, sys.stdin.readline().split())
    if a + b + c >= 2:
        result = result + 1
print(result)
