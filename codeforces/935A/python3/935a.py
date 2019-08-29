n = int(input())
s = int(n ** 0.5)
ans = 0

for i in range(1, s+1):
    if n % i == 0:
        if i == 1 or (i == s and n == s*s):
            ans += 1
        else:
            ans += 2

print(ans)
