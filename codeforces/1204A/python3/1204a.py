def solve(s):
    if len(s) == 0:
        return 0

    l = len(s)
    n = s.count('1')

    return (l + 1) // 2 if n > 1 else l // 2


s = input()
print(solve(s))
