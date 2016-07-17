index = int(input()) - 1
names= ["Sheldon", "Leonard", "Penny", "Rajesh", "Howard"]

x = 1
cur = 5*x
while index >= cur:
    index -= cur
    x *= 2
    cur = 5*x

print(names[int(index / x)])
