import sys

def check(n, an):
    a25 = 0
    a50 = 0
    for a in an:
        if a == 25:
            a25 += 1
        elif a == 50:
            if a25 < 1:
                return False
            a25 -= 1
            a50 += 1
        elif a == 100:
            if a25 < 1:
                return False
            
            if a50 > 0:
                a50 -= 1
                a25 -= 1
            else:
                if a25 < 3:
                    return False
                a25 -= 3

    return True

n = int(input())
an = list(map(int, sys.stdin.readline().split()))

if check(n, an):
    print("YES")
else:
    print("NO")
