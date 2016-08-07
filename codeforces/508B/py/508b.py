num = input()
length = len(num)
last = ord(num[length-1]) - ord('0')
even = -1
for i in range(length):
    digit = ord(num[i]) - ord('0')
    if digit % 2 == 0:
        if digit < last:
            even = i
            break
        else:
            even = i

if even is -1:
    print(-1)
else:
    ans = list(num)
    ans[even], ans[length-1] = ans[length-1], ans[even]
    print(''.join(ans))
        
