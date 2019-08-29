l = int(input())
s = input()
ans = ''
i = 0
step = 1
while i < l:
    ans += s[i]
    i += step
    step += 1

print(ans)
