import sys

an = list(map(int, sys.stdin.readline().split()))
s  = input()

result = 0
for c in s:
    result += an[ord(c) - ord('1')]

print(result)
