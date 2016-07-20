word = input()

lower = 0
for c in word:
    if ord(c) >= ord('a') and ord(c) <= ord('z'):
        lower += 1

if lower < len(word) - lower:
    print(word.upper())
else:
    print(word.lower())
