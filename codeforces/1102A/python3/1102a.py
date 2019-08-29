def dividing(n):
    if n % 4 == 0:
        return 2
    if n % 2 == 0:
        return 1
    return 0


n = int(input())
count1 = dividing(n)
count2 = dividing(n+1)
if count1 + count2 >= 2:
    print('0')
else:
    print('1')
