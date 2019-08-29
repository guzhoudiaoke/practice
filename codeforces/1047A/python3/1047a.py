def sum_of_digits(n):
    ans = 0
    while n != 0:
        ans += (n % 10)
        n = n // 10

    return ans


n = int(input())
a, b, c = 1, 1, n - 2
if sum_of_digits(c) % 3 == 0:
    b, c = 2, n - 3

print(a, b, c)
