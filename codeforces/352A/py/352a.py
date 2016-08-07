import sys

n = int(input())
an = list(map(int, sys.stdin.readline().split()))

zeros = 0
fives = 0
for i in range(n):
    if an[i] == 0:
        zeros += 1
    else:
        fives += 1

if zeros is 0:
    print(-1)
elif fives < 9:
    print(0)
else:
    ans = '5'*(fives - fives % 9)
    ans += '0'*zeros
    print(ans)
