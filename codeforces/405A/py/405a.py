import sys

n = int(input())
nums = list(map(int, sys.stdin.readline().split()))

nums = sorted(nums)
print(' '.join(map(str, nums)))
