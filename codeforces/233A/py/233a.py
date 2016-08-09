n = int(input())
if n % 2 is not 0:
    print(-1)
else:
    an = list(range(1, n+1))
    i = 0
    while i < n:
        an[i], an[i+1] = an[i+1], an[i]
        i += 2
    for i in range(n):
        print(an[i], end=' ')
    print()
