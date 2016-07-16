found = [False] * 26
name = input()

num = 0
for i in range(len(name)):
    if found[ord(name[i]) - ord('a')] == False:
        found[ord(name[i]) - ord('a')] = True
        num += 1

if num % 2 == 0:
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")
