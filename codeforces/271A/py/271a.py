
def is_beautiful(y):
    have = [0] * 10
    while y != 0:
        mod = y % 10
        if have[mod]:
            return False
        else:
            have[mod] = True
        y = int(y / 10)

    return True

year = int(input())

i = 0
for i in range(year+1, 10000):
    if is_beautiful(i):
        break
print(i)
