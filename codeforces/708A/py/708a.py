s = input()
t = ""

l = len(s)
a = 'a' * l

if s == a:
    t = 'a' * (l-1) + 'z'
else:
    i = 0
    while i < l:
        if s[i] == 'a':
            t += 'a'
        else:
            break
        i += 1

    while i < l:
        if s[i] != 'a':
            t += str(chr(ord(s[i]) - 1))
        else:
            break
        i += 1

    while i < l:
        t += str(s[i])
        i += 1

print(t)
