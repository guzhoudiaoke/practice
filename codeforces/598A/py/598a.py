
def solve(n):
    sum = n*(n+1) >> 1
    a = 1
    while a <= n:
        sum -= 2*a
        a *= 2
    return sum

t = int(input())
for i in range(t):
    n = int(input())
    print(solve(n))
