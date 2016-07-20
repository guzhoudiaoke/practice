n = int(input())

if n >= 0:
    print(n)
else:
    n = -n
    mod = n % 10
    n1 = int(n / 10)
    n2 = int(n / 100) * 10 + mod
    n = min(n1, n2)
    print(-n)
