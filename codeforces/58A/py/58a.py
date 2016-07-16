s = input()
dst = "hello"

id = 0
for i in range(len(s)):
    if s[i] == dst[id]:
        id += 1
    if id == len(dst):
        break

if id == len(dst):
    print("YES")
else:
    print("NO")
