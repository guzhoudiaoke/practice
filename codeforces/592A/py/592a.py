import sys

m = []
for i in range(8):
    m.append(input())

a = -1
b = -1
for i in range(8):
    for col in range(8):
        if m[i][col] == 'W':
            a = i
            for j in range(i):
                if m[j][col] != '.':
                    a = -1
                    break

            if a != -1:
                break
    if a != -1:
        break

i = 7
while i >= 0:
    col = 0
    while col < 8:
        if m[i][col] == 'B':
            b = i
            j = i+1
            while j < 8:
                if m[j][col] != '.':
                    b = -1
                    break
                j += 1

            if b != -1:
                break
        col += 1
    if b != -1:
        break
    i -= 1

if a <= (7-b):
    print("A")
else:
    print("B")

#.BB.B.B.
#B..B..B.
#.B.BB...
#BB.....B
#BBB....B
#B..BB...
#BB.B...B
#....WWW.
