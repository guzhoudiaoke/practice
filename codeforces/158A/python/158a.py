import sys

n, k = map(int, sys.stdin.readline().split())

scores = [int(i) for i in input().split()]

ret = 0
while ret < n and scores[ret] > 0 and scores[ret] >= scores[k-1]:
	ret = ret+1

print(ret);
