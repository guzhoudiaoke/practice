
def is_lucky(n):
    if n is 0:
        return False

    while n != 0:
        mod = n % 10
        n = int(n / 10)
        if mod != 4 and mod != 7:
            return False

    return True

num = input()
n = 0
for i in range(len(num)):
    if num[i] == '4' or num[i] == '7':
        n += 1

if (is_lucky(n) == True):
    print("YES")
else:
    print("NO")



