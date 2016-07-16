import sys

line = input()
count = {'1': 0, '2':0, '3':0}
for i in range(len(line)):
    if line[i] != '+':
        count[line[i]] = count[line[i]] + 1

result = ""
for i in range(count['1']):
    result = result + "1+"
for i in range(count['2']):
    result += "2+"
for i in range(count['3']):
    result = result + "3+"

result = result[:-1]
print(result)
