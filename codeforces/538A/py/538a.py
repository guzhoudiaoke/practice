src = input()
dst = 'CODEFORCES'

ans = False
delta = len(src) - len(dst)
if delta > 0:
    for i in range(0, len(src) - delta + 1):
        t = src[0:i] + src[i+delta:len(src)]
        if t == dst:
            ans = True
            break

if ans:
    print("YES")
else:
    print("NO")
