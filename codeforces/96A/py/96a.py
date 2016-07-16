import sys

players = input()
if players.find('0000000') >= 0 or players.find('1111111') >= 0:
    print("YES")
else:
    print("NO")
