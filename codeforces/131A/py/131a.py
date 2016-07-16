import sys

def is_upper(ch):
    return ch >= 'A' and ch <= 'Z'

s = input()
count = 0
for i in range(1, len(s)):
    if is_upper(s[i]):
        count = count + 1

result = ""
if (count == len(s) - 1):
    for i in range(len(s)):
        if (is_upper(s[i])):
            result = result + (s[i].lower())
        else:
            result = result + (s[i].upper())
else:
    result = s

print(result)
