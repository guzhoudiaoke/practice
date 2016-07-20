import sys

cn = list(map(int, sys.stdin.readline().split()))
total = sum(cn)
if total >= 5 and total % 5 == 0:
    print(int(total / 5))
else:
    print("-1")
