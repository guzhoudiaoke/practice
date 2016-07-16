import sys

n = int(input())
line = input()
list = line.split()

groups = {"1": 0, "2": 0, "3": 0, "4": 0}
for i in range(len(list)):
    groups[list[i]] = groups[list[i]] + 1

result = groups['4'] + groups['3']
groups['1'] = max(0, groups['1'] - groups['3'])
result = result + int((groups['2'] + 1) / 2)
groups['1'] = max(0, groups['1'] - 2*(groups['2'] % 2))
result = result + int((groups['1'] + 3) / 4)

print(result)
