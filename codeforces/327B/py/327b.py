import sys

n = int(input())
ans = ""
for i in range(n):
    ans += str(3*n+i)
    ans += " "
print(ans)
