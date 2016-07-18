song = input()
result = ""

i = 0
while i < len(song):
    if i + 2 < len(song) and song[i] == 'W' and song[i+1] == 'U' and song[i+2] == 'B':
        if len(result) == 0 or not result[-1].isspace():
            result += ' '
        i += 3
    else:
        result += song[i]
        i += 1

print(result.strip())
