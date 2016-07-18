import sys

n = int(input())
x = 0
y = 0
z = 0
for i in range(n):
    a, b, c = map(int, sys.stdin.readline().split())
    x += a
    y += b
    z += c

if x is 0 and y is 0 and z is 0:
    print("YES")
else:
    print("NO")


