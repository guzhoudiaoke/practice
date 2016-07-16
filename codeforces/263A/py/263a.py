import sys

c_size = 5

ll = []
row = 0
col = 0
for i in range(c_size):
    ll.append(list(map(int, sys.stdin.readline().split())))
    for j in range(c_size):
        if ll[i][j] == 1:
            row = i
            col = j

mid = int(c_size / 2)
print(abs(row-mid) + abs(col-mid))
