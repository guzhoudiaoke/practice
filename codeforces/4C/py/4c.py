n = int(input())
dict = {}
for i in range(n):
    name = input()
    if dict.get(name) == None:
        dict[name] = 1
        print("OK")
    else:
        print(name, dict[name], sep='')
        dict[name] += 1
