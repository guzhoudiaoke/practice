def get_line(index, n):
    if index > n:
        index = n*2 - index

    nnum = 2*index + 1
    nspace = (2*n + 1 - nnum)
    line = ' ' * (nspace)
    for i in range(nnum):
        if i != 0:
            line += ' '
        if i <= int(nnum/2):
            line += str(i)
        else:
            line += str(nnum-i - 1)

    return line

n = int(input())

for i in range(n*2 + 1):
    line = get_line(i, n)
    print(line)
