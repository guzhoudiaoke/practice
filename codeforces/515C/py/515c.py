n = int(input())
s = input()

trans = ['', '', '2', '3', '322', '5', '53', '7', '7222', '7332']
ans = ''

for c in s:
    ans += trans[ord(c) - ord('0')]

ans_list = list(ans)
ans_list.sort(reverse=True)
print(''.join(ans_list))
