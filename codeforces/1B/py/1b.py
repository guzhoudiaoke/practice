import re

mtoza = []
def get_type(s):
    p = re.compile('R\d+C\d+')
    if p.match(s) != None:
        return 1
    return 0
    
def num_to_az(s):
    c = int(s)
    line = ""
    while c != 0:
        line = mtoza[(c-1) % 26] + line
        c = c - (c-1) % 26
        c = int(c / 26)
    return line

def az_to_num(s):
    n = 0
    for x in s:
        n *= 26
        n += 1 + ord(x) - ord('A')

    return str(n)

def translate_1(org):
    i = org.find('C')
    rstr = org[1 : i]
    cstr = org[i+1 : len(org)]
    return num_to_az(cstr) + rstr

def translate_2(org):
    i = 0
    while i < len(org) and org[i].isalpha():
        i += 1
    line = "R" + org[i : len(org)] + "C" + az_to_num(org[0 : i])
    return line


n = int(input())
for i in range(26):
    mtoza.append(chr(ord('A') + i))

for i in range(n):
    org = input()
    if len(org) == 0:
        continue

    if get_type(org) == 1:
        print(translate_1(org))
    else:
        print(translate_2(org))
