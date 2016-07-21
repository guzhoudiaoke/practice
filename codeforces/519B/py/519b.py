import sys

n = int(input())
an = list(map(int, sys.stdin.readline().split()))
bn = list(map(int, sys.stdin.readline().split()))
cn = list(map(int, sys.stdin.readline().split()))

a = 0
for d in an:
    a ^= d

b = 0
for d in bn:
    b ^= d

c = 0
for d in cn:
    c ^= d

print(a ^ b)
print(b ^ c)
