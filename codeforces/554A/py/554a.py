import sys

s = input()

booklets = set()
for i in range(0, 1+len(s)):
    for c in range(ord("a"), ord("z")+1):
        news = s[0:i] + chr(c) + s[i:]
        booklets.add(news)

print(len(booklets))
