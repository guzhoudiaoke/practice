n = int(input())

ans = ['o' for i in range(n)]
f1, f2, f3 = 1, 1, 2
while f1 <= n:
    ans[f1-1] = 'O'
    f1, f2, f3 = f2, f3, f2+f3

print(''.join(ans))
