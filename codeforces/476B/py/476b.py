import math

def combine(n, m):
    ret = 1
    for i in range(m+1, n+1):
        ret *= i
    for i in range(1, n-m+1):
        ret /= i

    return ret


send = input()
recv = input()

dst = 0
for c in send:
    if c is '+':
        dst += 1
    else:
        dst -= 1

cur = 0
cnt = 0
for c in recv:
    if c is '+':
        cur += 1
    elif c is '-':
        cur -= 1
    else:
        cnt += 1

mov = dst - cur
ans = 1.0
if abs(mov) > cnt or (mov + cnt) % 2 != 0:
    ans = 0.0
else:
    positive = (mov + cnt) // 2
    ans = combine(cnt, positive) / math.pow(2, cnt)

print(ans)

