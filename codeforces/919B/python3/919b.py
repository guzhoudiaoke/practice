def sum_of_digits(n):
    ans = 0
    while n != 0:
        ans += n % 10
        n = n // 10
    return ans


k = int(input())
ans = 19
while True:
    while sum_of_digits(ans) != 10:
        ans += 9

    k -= 1
    if k == 0:
        break
    
    ans += 9

print(ans)
