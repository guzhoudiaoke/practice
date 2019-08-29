n = int(input())
s = input()

begin = 0
end = 0
ans = 0
while begin < n:
    while begin < n and s[begin] != 'x':
        begin += 1

    if begin >= n:
        break

    end = begin + 1
    while end < n and s[end] == 'x':
        end += 1

    if end - begin >= 3:
        ans += end - begin - 2

    begin = end

print(ans)
