import sys

s = input()
find = False
find = s.find('H') >= 0 or s.find('Q') >= 0 or s.find('9') >= 0
if find:
    print("YES")
else:
    print("NO")
