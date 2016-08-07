s = input()

index = 0
ans = True
length = len(s)
for i in range(length):
    if s[i] is not '1' and s[i] is not '4':
        ans = False
        break

if s[0] is not '1':
    ans = False

if s.find('444') >= 0:
    ans = False

if ans is True:
    print("YES")
else:
    print("NO")
