import math

n = int(input())
is_prime = [True] * (n+1)

for i in range(2, int(math.sqrt(n)) + 1):
    if is_prime[i]:
        for j in range(2, int(n/i)):
            is_prime[i*j] = False

x = int(n / 2)
while x >= 4:
    if (not is_prime[x]) and (not is_prime[n-x]):
        break
    x -= 1

print(x, n-x, sep=' ')
