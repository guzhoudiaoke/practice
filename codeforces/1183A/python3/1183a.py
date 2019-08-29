def sum_of_digits(n):
    ans = 0
    while n > 0:
        ans += n % 10
        n = n // 10
    return ans


def solve(n):
    while sum_of_digits(n) % 4 != 0:
        n += 1
    return n


a = int(input())
print(solve(a))
