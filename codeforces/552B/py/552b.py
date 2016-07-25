nstr = input()
n = int(nstr)

#ans = 0
#for i in range(1, len(nstr)+1):
#    if i < len(nstr):
#        ans += 9 * 10**(i-1) * i
#    else:
#        ans += (n - 10**(i-1) + 1) * i

ans = (n+1) * len(nstr)
ans -= int('1'*len(nstr))

print(ans)
