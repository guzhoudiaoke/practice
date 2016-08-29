n = int(input())

aa = 1234567
bb = 123456
cc = 1234

ans = False
a = 0
while ans is False:
    left = n - a
    if left < 0:
        break

    b = 0
    while ans is False:
        leftleft = left - b
        if leftleft < 0:
            break

        if leftleft % cc == 0:
            ans = True
            break
        b += bb
    a += aa

if ans is True:
    print("YES")
else:
    print("NO")   
