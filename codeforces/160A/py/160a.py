import sys

def calc(count, sum):
    cur = 0
    num = 0
    for i in range(len(count)-1, 0, -1):
        for j in range(count[i]):
            cur += i
            num += 1
            if cur > sum-cur:
                return num
    return num

n = int(input())
l = list(map(int, sys.stdin.readline().split()))

count = [0] * 101
sum = 0
for i in range(len(l)):
    count[l[i]] += 1
    sum += l[i]

print(calc(count, sum))
