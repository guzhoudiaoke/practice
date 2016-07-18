import sys

def gcd(a, b):
        if b == 0:
                return a
        return gcd(b, a % b)

a, b, n = map(int, sys.stdin.readline().split())
result = True
while n > 0:
        if result == True:
                rm = gcd(a, n)
        else:
                rm = gcd(b, n)

        if n < rm:
                break

        result = not result
        n -= rm

if result == True:
        print("1")
else:
        print("0")
