num = input()

result = ""
for i in range(len(num)):
    ch = num[i]
    if not (i == 0 and ch == '9') and (ord(ch) - ord('0') > ord('9') - ord(ch)):
        result += str(ord('9') - ord(ch))
    else:
        result += ch

print(result)
