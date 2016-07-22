import sys

inputs = sys.stdin.readline().split()
x = int(inputs[0])

out = 0
if inputs[2] == "week":
    w = 5
    for i in range(366):
        if w == x:
            out += 1
        w += 1
        if w == 8:
            w = 1
else:
    if x <= 29:
        out = 12
    if x == 30:
        out = 11
    if x == 31:
        out = 7

print(out)
