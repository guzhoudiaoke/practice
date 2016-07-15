import sys

n = int(input())
result = 0
for i in range(n):
    cmd = input()
    if cmd == "++X" or cmd == "X++":
        result = result + 1
    elif cmd == "--X" or cmd == "X--":
        result = result - 1

print(result)
