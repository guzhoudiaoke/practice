m = int(input())
d = {
        'purple' : 'Power',
        'green'  : 'Time',
        'blue'   : 'Space',
        'orange' : 'Soul',
        'red'    : 'Reality',
        'yellow' : 'Mind'
}

for _ in range(m):
    c = input()
    del d[c]

print(len(d))
for _, v in d.items():
    print(v)
