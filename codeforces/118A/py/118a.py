import sys

word = input()
word = word.lower()

result = ""
for i in range(len(word)):
    if not (word[i] == 'a' or word[i] == 'o' or word[i] == 'y' or
            word[i] == 'e' or word[i] == 'u' or word[i] == 'i'):
        result += '.'
        result += word[i]

print(result)
