import sys

n, t = map(int, sys.stdin.readline().split())
q = list(input())

for i in range(t):
    index = 0
    while index + 1 < n:
        if q[index] == 'B' and q[index + 1] == 'G':
            q[index], q[index + 1] = q[index + 1], q[index]
            
            index += 2
        else:
            index += 1

print("".join(q))
