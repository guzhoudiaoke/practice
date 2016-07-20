n = int(input())

level = 0
cur = 1

while n >= cur:
    level += 1
    n -= cur
    cur += (level + 1)

print(level)
