s = input()

total = 0
q = [0 for i in range(len(s))]
for i in range(len(s)):
    if s[i] == 'Q':
        total += 1
    q[i] = total

ans = 0
for i in range(len(s)):
    if s[i] == 'A':
        ans += q[i] * (total - q[i])

print(ans)
