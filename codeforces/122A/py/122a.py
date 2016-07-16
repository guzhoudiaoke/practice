def is_lucky(num):
    while (num):
        mod = num % 10
        num = int(num / 10)
        if mod != 4 and mod != 7:
            return False
    return True

def almost_lucky(num):
    for i in range(4, num+1):
        if is_lucky(i) == True:
            if num % i == 0:
                return True
    return False
    

num = int(input())
if almost_lucky(num) == True:
    print("YES")
else:
    print("NO")
