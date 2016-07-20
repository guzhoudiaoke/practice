import sys

n = int(input())
ap = []
for i in range(n):
    a, p = map(int, sys.stdin.readline().split())
    ap.append([a, p])
    

cost = 0
id = 0
while id < n:
    price = ap[id][1]
    while id < n and price <= ap[id][1]:
        cost += price * ap[id][0]
        id += 1

print(cost)
    
