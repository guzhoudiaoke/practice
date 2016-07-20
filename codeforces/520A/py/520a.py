import sys

n = int(input())
line = input()

find = [0] * 26
for i in range(n):
    find[ord(line[i].lower()) - ord('a')] = 1

all = 1
for i in range(26):
    if find[i] == 0:
        all = 0
        break

if all:
    print("YES")
else:
    print("NO")
