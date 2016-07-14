import sys

n = int(input())
while n != 0:
	s = input()
	l = len(s)
	if (l <= 10):
		print(s)
	else:
		print(s[0], l-2, s[l-1], sep='')
	n = n-1
