import sys

n = int(input())
heights = list(map(int, sys.stdin.readline().split()))

min_index = 0
min_value = heights[0]
max_index = 0
max_value = heights[0]

for i in range(1, len(heights)):
    if heights[i] <= min_value:
        min_value = heights[i]
        min_index = i
    if heights[i] > max_value:
        max_value = heights[i]
        max_index = i

mov = max_index + (len(heights) - 1 - min_index)
if max_index > min_index:
    mov -= 1

print(mov)
