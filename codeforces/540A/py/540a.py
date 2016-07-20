n = int(input())
dst = input()
src = input()

step = 0
for i in range(n):
    mov = abs(ord(dst[i]) - ord(src[i]))
    if mov > 5:
        mov = 10 - mov
    step += mov

print(step)
