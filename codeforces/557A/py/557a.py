import sys

n = int(input())
min1, max1 = map(int, sys.stdin.readline().split())
min2, max2 = map(int, sys.stdin.readline().split())
min3, max3 = map(int, sys.stdin.readline().split())

first_max = n - min2 - min3
first = 0
second = 0
third = 0
if first_max <= max1:
    first = first_max
else:
    first = max1

n = n - first
second_max = n - min3
if second_max <= max2:
    second = second_max
else:
    second = max2

third = n - second

print(first, second, third)
