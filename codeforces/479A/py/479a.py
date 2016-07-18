a = int(input())
b = int(input())
c = int(input())

m = a + b + c
m = max(m, (a+b) * c)
m = max(m, a * (b+c))
m = max(m, a * b * c)

print(m)
