n = int(input())

# each guess make n-i+1 mistakes
# the ith guess cost i
ret = n
for i in range (1, n):
    ret += i * (n-i)

print(ret)
