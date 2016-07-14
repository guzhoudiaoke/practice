import sys 

m, n, a = map(int, sys.stdin.readline().split())
num = int((m + a - 1) / a) * int((n + a - 1) / a)
print(num)
