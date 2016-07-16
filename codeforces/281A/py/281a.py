import sys

word = input()
if word[0] >= 'a' and word[0] <= 'z':
    word = word[0].upper() + word[1:]

print(word)
