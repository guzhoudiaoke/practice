import sys

def calc_ones(n):
    ret = 0
    while n > 0:
        ret += n & 1
        n >>= 1
    return ret

n, m, k = map(int, sys.stdin.readline().split())
army = [0] * (m+1)
for i in range (m+1):
    army[i] = int(input())

result = 0
for i in range(m):
    if calc_ones(army[i] ^ army[m]) <= k:
        result += 1

print(result)
