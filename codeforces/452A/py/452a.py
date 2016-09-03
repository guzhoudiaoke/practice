n = int(input())
s = input()
l = ["vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"]

ans = 0
for i in range(0, len(l)):
    if len(l[i]) != n:
        continue

    find = True
    for j in range(n):
        if l[i][j] != s[j] and s[j] != '.':
            find = False
            break

    if find:
        ans = i
        break

print(l[i])
