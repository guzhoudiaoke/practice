import sys

n, m = map(int, sys.stdin.readline().split())
s = input()

left = 0
right = 0
ans = 0
while True:
    left = s.find('.', right)
    if left < 0:
        break

    right = left+1
    while right < n and s[right] == '.':
        right += 1

    if right - left > 1:
        ans += right-left-1

l = list(s)
ans_list = []
for i in range(m):
    query = list(sys.stdin.readline().split())
    xi = int(query[0]) - 1
    ci = query[1]
    if (ci == '.' and l[xi] == '.') or (ci != '.' and l[xi] != '.'):
        pass
    elif ci == '.' and l[xi] != '.':
        if xi > 0 and l[xi-1] == '.':
            ans += 1
        if xi < n-1 and l[xi+1] == '.':
            ans += 1
    elif ci != '.' and l[xi] == '.':
        if xi > 0 and l[xi-1] == '.':
            ans -= 1
        if xi < n-1 and l[xi+1] == '.':
            ans -= 1

    ans_list.append(ans)
    l[xi] = ci

print('\n'.join(map(str, ans_list)))
