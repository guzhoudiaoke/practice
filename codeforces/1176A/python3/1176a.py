q = int(input())
for i in range(q):
    n = int(input())
    cnt2, cnt3, cnt5 = 0, 0, 0
    while n % 2 == 0:
        n //= 2
        cnt2 += 1
    while n % 3 == 0:
        n //= 3
        cnt3 += 1
    while n % 5 == 0:
        n //= 5
        cnt5 += 1

    if n != 1:
        print(-1)
    else:
        print(cnt2 + 2*cnt3 + 3*cnt5)
