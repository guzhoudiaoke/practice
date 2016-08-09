
def is_lucky(n):
    s = str(n)
    for i in range(len(s)):
        if s[i] == '8':
            return True
    return False

a = int(input())
step = 0
while a < 8888888888:
    if step is not 0 and is_lucky(a):
        break
    a += 1
    step += 1

print(step)
