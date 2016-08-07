n = int(input())

row = [0] * n
col = [0] * n
for i in range(n):
    line = input()
    for j in range(n):
        if line[j] == 'C':
            row[i] += 1
            col[j] += 1

ans = 0
for i in range(n):
    if row[i] > 0:
        ans += row[i] * (row[i]-1) // 2
    if col[i] > 0:
        ans += col[i] * (col[i]-1) // 2

print(ans)
