x = input()
y = input()

z = ""
for i in range(len(x)):
    if x[i] == y[i]:
        z += "0"
    else:
        z += "1"

print(z)
