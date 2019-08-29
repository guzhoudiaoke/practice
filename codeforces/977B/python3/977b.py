n = int(input())
s = input()

d = {}
ans = ''
m = 0
for i in range(n-1):
    ss = s[i:i+2]

    if ss not in d:
        d[ss] = 1
    else:
        d[ss] += 1

    if d[ss] > m:
        m = d[ss]
        ans = ss

print(ans)
