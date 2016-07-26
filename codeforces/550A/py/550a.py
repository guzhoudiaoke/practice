s = input()

result = False
ab = s.find('AB')
ba = -1
if ab != -1:
    ba = s.find('BA', ab+2)
    if ba != -1:
        result = True

if not result:
    ba = s.find('BA')
    if ba != -1:
        ab = s.find('AB', ba+2)
        if ab != -1:
            result = True

if result:
    print("YES")
else:
    print("NO")
