import sys

n, k, l, c, d, p, nl, np = map(int, sys.stdin.readline().split())
drink = k*l
limes = c*d
salt = p

toasts = min(min(int(drink/nl), limes), int(salt/np))
each = int(toasts/n)
print(each)
