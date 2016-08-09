n = int(input())
ans = ''
for i in range(n):
    if i is not n-1:
        if i % 2 == 0:
            ans += 'I hate that '
        else:
            ans += 'I love that '
    else:
        if i % 2 == 0:
            ans += 'I hate it'
        else:
            ans += 'I love it'

print(ans)
