n = input()
ans = 1
for x in n:
    ans *= 2
    if x == '7':
        ans += 1

print(ans - 1)
