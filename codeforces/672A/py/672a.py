n = int(input())

if n <= 9:
    print(n)
elif n <= 99:
    num = (n - 10) / 2 + 10
    mod = (n - 10) % 2
    s = str(num)
    print(s[mod])
else:
    num = (n - 10 - 90 * 2) / 3 + 100
    mod = (n - 10 - 90 * 2) % 3
    s = str(num)
    print(s[mod])
