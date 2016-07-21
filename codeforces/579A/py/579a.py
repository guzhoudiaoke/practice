x = int(input())

ret = 0
while x > 0:
    if x & 1:
        ret += 1
    x >>= 1

print(ret)
