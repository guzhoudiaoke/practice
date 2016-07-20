import sys

n = int(input())
x = list(map(int, sys.stdin.readline().split()))
y = list(map(int, sys.stdin.readline().split()))

levels = [0] * (n+1)
for i in range(1, x[0]+1):
    levels[x[i]] += 1
for i in range(1, y[0]+1):
    levels[y[i]] += 1

is_pass = True
for i in range(1, n+1):
    if levels[i] == 0:
        is_pass = False

if is_pass:
    print("I become the guy.")
else:
    print("Oh, my keyboard!")
