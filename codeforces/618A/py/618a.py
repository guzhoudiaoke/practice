n = int(input())

ans = ""
for i in range(32, -1, -1):
    if n & (1 << i) is not 0:
        ans += str(i + 1)
        ans += ' '
print(ans)
